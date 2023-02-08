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
    if (_interrupt_singal_flag)
    {
        _iterate_clients(
            [] (auto && client) 
            {
                if (client.client_thread.joinable())
                {
                    client.client_thread.join(); 
                }   
            }
        );
    }
    else if (_termination_singal_flag)
    {
        _iterate_clients(
            [] (auto && client) 
            {
                client.client_thread.detach();
            }
        );
    }
    else // runtime asserts ?
    {

    }
}

void NetworkServerSide::_print_client(std::string_view data)
{
    (void)data;
    {
        std::lock_guard<std::mutex> print_lock(_access_to_clients);
    }
}