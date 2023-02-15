#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <thread>
#include <mutex>
#include <string>
#include <limits>
#include <optional>

/**
 * @brief Headers for C build-in for libraries
*/

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    using ____max_supported_connection_id_type = uint32_t;

    using ____user_id_type = ____max_supported_connection_id_type;

/**
 * @brief Local/Global definitons
*/

  inline constexpr uint32_t  __maximal_count_of_clients
                = std::numeric_limits<____max_supported_connection_id_type>::max();

/** @brief Struct represents info needed for server side */
struct client_connection_info__SERVER_SIDE final
{
    public:
        /** @brief Constructor represents direct initialization of variables */
        client_connection_info__SERVER_SIDE(std::thread && _client_thread,
                                                     int _socket_file_descriptor)
                                                     :
                                                     client_thread(std::move(_client_thread)),
                                                     socket_file_descriptor(_socket_file_descriptor)

        {
        }

        /** @brief Move constructor - in default state */
        client_connection_info__SERVER_SIDE(client_connection_info__SERVER_SIDE &&) = default;
        /** @brief Move assigment operator - in default state */
        client_connection_info__SERVER_SIDE& operator=(client_connection_info__SERVER_SIDE &&) = default;

        /** @brief Copy constructor - unvailble */
        client_connection_info__SERVER_SIDE(client_connection_info__SERVER_SIDE const&) = delete;
        /** @brief Copy assigment operator - unvailble */
        client_connection_info__SERVER_SIDE& operator=(client_connection_info__SERVER_SIDE const&) = delete;

    public:
        /** @brief Thread handle of client */
        std::thread client_thread;
        /** @brief Client name */
        std::optional<std::string> client_name;
        /** @brief FD for client */
        int socket_file_descriptor;
};


/** @brief Struct represents info needed for client side */
struct client_connection_info__CLIENT_SIDE final
{
    public:
        /** @brief Constructor represents direct initializaion of handle */
        explicit client_connection_info__CLIENT_SIDE(std::thread && _client_receiver,
                                                     std::thread && _client_sender)
                                                     :
                                                     client_receiver(std::move(_client_receiver)),
                                                     client_sender(std::move(_client_sender))
        {}

        client_connection_info__CLIENT_SIDE(client_connection_info__CLIENT_SIDE const&) = delete;
        client_connection_info__CLIENT_SIDE(client_connection_info__CLIENT_SIDE &&) = delete;

        client_connection_info__CLIENT_SIDE& operator=(client_connection_info__CLIENT_SIDE const&) = delete;
        client_connection_info__CLIENT_SIDE& operator=(client_connection_info__CLIENT_SIDE &&) = delete;


    public:
        /** @brief Thread handle for client receiver */
        std::thread client_receiver;
        /** @brief Thread handle for client sender */
        std::thread client_sender;
}; 