#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <unordered_map>
#include <atomic>
#include <algorithm>
#include <memory>
#include <array>
#include <shared_mutex>

/**
 * @brief Headers for C build-in for libraries
*/

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../../network/Base/headers/NetworkBase.hpp"
#include "../../thread/header/ThreadConfig.hpp"
#include "../../support/headers/MSupportTerminalServerMaintenance.hpp"

/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    inline constexpr int __connection_queue_max_lenght = 10;
    inline constexpr uint16_t __maximal_name_size      = (uint16_t)35;

/**
 * @brief Local/Global definitons
*/
class NetworkServerSide final : public iNetworkBase
{
    private:
        /** @brief Map of client info */
        std::unordered_map<____user_id_type, client_connection_info__SERVER_SIDE> _clients;

        /** @brief Mutex for accesing to client info */
        std::mutex _access_to_clients;
        
        std::shared_mutex _access_to_clients_name;

        std::vector<std::optional<std::string_view>> _client_names;
    
        /** @brief Offset for client id */
        ____user_id_type _id_of_clients_offset;
    
    private:
        /** @brief Atomic flag for interrupt signal */
        static std::atomic_bool _interrupt_singal_flag;    
        /** @brief Atomic flag for termination signal */
        static std::atomic_bool _termination_singal_flag;    

    public:
        NetworkServerSide() : iNetworkBase()
        {
            int res_of_bind = bind(get_server_socket_fd(),
                                  reinterpret_cast<struct sockaddr *>(&__socket_info.socket_info),
                                  sizeof(struct sockaddr_in));
            RES_NETWORK_CHECK_SYS_CALL(res_of_bind, __error_network_bind_BIT);
            
            int res_of_listen = listen(get_server_socket_fd(),
                                       __connection_queue_max_lenght);
            RES_NETWORK_CHECK_SYS_CALL(res_of_listen, __error_network_listen_BIT);
        
        }

    private:
        /**
         * @brief Iteration member function
         * @param lambda Lambda which is pass to std::for_each
        */
        template <typename Lambda>
        inline void _iterate_clients(Lambda && lambda)
        {
            std::for_each(_clients.begin(), _clients.end(),
                          std::forward<Lambda>(lambda));
        }

    public:
        /**
         * @brief Client registration thread function
        */
        void client_registration();
        /**
         * @brief Server maintennace thread function
        */
        void server_maintenance();

    private:
        void _exit_connected_clients(); 
    
    private:
        /**
         * @brief Print client information
         * @param data Data about clients that should be printed to terminal
        */
        void _print_client(std::string && data);

        void _exit_clients(std::string && data);
    
    private:
        void _broadcast_message();
        void _unicast_message();
        void _multicast_message();
    
    private:
        void _client_handle(int client_id, int client_socket_fd);
        std::string _name_control_handle(int client_socket_fd);
        void _server_handle();

    private:
        /**
         * @brief Signal handler for interrupt signal
         * @param signal Value of signal
        */
        static void _interrupt_signal_handler(int signal);    
        /**
         * @brief Signal handler for termination signal
         * @param signal Value of signal
        */
        static void _termination_signal_handler(int signal);    
    
    public:
        /**
         * @brief Initialized signal handlers for server side
        */
        void init_signal() override;
}; 
