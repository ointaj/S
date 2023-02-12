/**
 * @brief Headers for C++ build-in for libraries
*/

/**
 * @brief Headers for C build-in for libraries
*/

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../headers/NetworkServerSite.hpp"
#include "../../support/headers/MSupportTerminal_I_O.hpp"

/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

/**
 * @brief Local/Global definitons
*/
std::atomic_bool NetworkServerSide::_interrupt_singal_flag = false;
std::atomic_bool NetworkServerSide::_termination_singal_flag = false;

void NetworkServerSide::client_registration()
{
    // Init signals berore main thread execution
    init_signal();

    while ((!_interrupt_singal_flag) && (!_termination_singal_flag))
    {
        socket_info new_client;
        socklen_t size_of_sockadd = sizeof(struct sockaddr);
        new_client.socket_fd = accept(get_server_socket_fd(),
                                      reinterpret_cast<struct sockaddr *>(&new_client.socket_info),
                                      &size_of_sockadd);
        RES_NETWORK_CHECK_SYS_CALL(new_client.socket_fd, __error_network_accept_BIT);
        
        {
            std::lock_guard<std::mutex> accept_lock(_access_to_clients);
            
            _id_of_clients_offset++;
            _clients.emplace_back(std::make_unique<client_connection_info__SERVER_SIDE>(
                                                     std::thread([this]() { this->_client_handle(); }),
                                                     _id_of_clients_offset,
                                                    new_client.socket_fd));
            // add to container and will run
        }
    }
    _exit_connected_clients();
}

void NetworkServerSide::_interrupt_signal_handler(int signal)
{
    (void)signal;
    _interrupt_singal_flag.store(true,
                                 std::memory_order_relaxed);
}

void NetworkServerSide::_termination_signal_handler(int signal)
{
    (void)signal;
     _termination_singal_flag.store(true,
                                  std::memory_order_relaxed);
}

void NetworkServerSide::init_signal()
{
    signal(SIGINT, NetworkServerSide::_interrupt_signal_handler);   
    signal(SIGTERM, NetworkServerSide::_termination_signal_handler);   
}

void NetworkServerSide::_exit_connected_clients()
{
    std::lock_guard<std::mutex> exit_lock(_access_to_clients);
    if (_interrupt_singal_flag)
    {
        _iterate_clients(
            [] (auto const& client) 
            {
                if (nullptr != client)
                {
                    if (client->client_thread.joinable())
                    {
                        client->client_thread.join(); 
                    }
                }
            }
        );
    }
    else if (_termination_singal_flag)
    {
        _iterate_clients(
            [] (auto const& client) 
            {
                if (nullptr != client)
                {
                    client->client_thread.detach();
                }
            }
        );
    }
    else
    {
        assert(false);
    }
}

void NetworkServerSide::_print_client(std::string && data)
{
    {
        std::lock_guard<std::mutex> print_lock(_access_to_clients);
        ServerTerminalSupport terminal_support(std::move(data));
        terminal_support.parse_terminal_input();
        if (terminal_support->chcek_command_bit(__PRINT_COMMAND_BITMASK))
        {
            IO::___clients data_to_print;
            auto ids = terminal_support->get_all_ids();

            for (auto id : ids)
            {
                if ((_clients.size() >= id) && (0 < id))
                {
                    const auto index = id - 1;
                    auto const& client = _clients.at(index);
                    if ((nullptr != client)
                         && (id == client->client_id)
                         && (std::nullopt != client->client_name))
                    {
                        data_to_print.emplace_back(std::make_pair(client->client_id, client->client_name->c_str()));
                    }
                }

            }
            if (!data_to_print.empty())
            {
                MSupportIO::terminal_ouput_clients(data_to_print);
            }
        }
        else if (terminal_support->chcek_command_bit(__PRINT_ALL_COMMAND_BITMASK))
        {
             IO::___all_clients data_to_print;
            _iterate_clients(
                [&data_to_print](auto const& client)
                {
                    if ((nullptr != client) && (std::nullopt != client->client_name))
                    {
                        data_to_print.emplace_back(client->client_name->c_str());
                    }
                });
            if (!data_to_print.empty())
            {
                MSupportIO::terminal_ouput_clients(data_to_print);
            }
        }
        else
        {
            assert(false);
        }
    }
}

void NetworkServerSide::_exit_clients(std::string && data)
{
    {  
        std::lock_guard<std::mutex> exit_lock(_access_to_clients);
        ServerTerminalSupport terminal_support(std::move(data));
        terminal_support.parse_terminal_input();
        if (terminal_support->chcek_command_bit(__EXIT_COMMAND_BITMASK))
        {
            auto ids = terminal_support->get_all_ids();
            for (auto id : ids)
            {
                auto index = id - 1;
                auto & client = _clients.at(index);
                if ((nullptr != client) && (id == client->client_id))
                {
                    client->client_thread.detach();
                    // maybe some sleep ?
                    client.release();
                }
            }
        }
        else if (terminal_support->chcek_command_bit(__EXIT_ALL_COMMAND_BITMASK))
        {
           _iterate_clients(
            [] (auto & client) 
            {
                if (nullptr != client)
                {
                    client->client_thread.detach();
                }
            });
            _id_of_clients_offset = 0;
            // Reset clients (de-allocated std::unique_ptr)
            _clients.clear();
            // call shrin_to_fit ? memory will be saved but effeciancy will be lost
            // effaciancy > memory in this case, i guess, so no shrink... we would loose preallocated blocks
        }
    }
}


void NetworkServerSide::_client_handle()
{

}
