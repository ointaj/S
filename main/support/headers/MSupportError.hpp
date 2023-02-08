#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

/**
 * @brief Headers for C build-in for libraries
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

/**
 * @brief Pre-proccesor defintions
*/
    /** @brief Macro for exit(3) */
    #define USERSPACE_EXIT(v) exit(v)

    /** @brief Macro for _exit(2) */
    #define KERNEL_EXIT _exit()

    #define INTERRUPT_SIGNAL SIGINT

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/
    /** @brief Macro for handling result */
    inline constexpr int __error_exit_status         = -1;
    /** @brief Macro for handling result */
    inline constexpr int __syscall_error             = __error_exit_status;

    /** @brief Error bitmask handle in case of connection fail */
    inline constexpr uint8_t __error_network_connect_BIT = uint8_t(1 << 0);
    /** @brief Error bitmask handle in case of bind fail */
    inline constexpr uint8_t __error_network_bind_BIT    = uint8_t(1 << 1);
    /** @brief Error bitmask handle in case of listen fail */
    inline constexpr uint8_t __error_network_listen_BIT  = uint8_t(1 << 2);
    /** @brief Error bitmask handle in case of accept fail */
    inline constexpr uint8_t __error_network_accept_BIT  = uint8_t(1 << 3);

    /** @brief Error message in case of connection fail */
    inline constexpr const char * __error_network_connect_TEXT = "Connnect failed : ";
    /** @brief Error message in case of bind fail */
    inline constexpr const char * __error_network_bind_TEXT    = "Bind failed : ";
    /** @brief Error message in case of listen fail */
    inline constexpr const char * __error_network_listen_TEXT  = "Listen failed : ";
    /** @brief Error message in case of accept fail */
    inline constexpr const char * __error_network_accept_TEXT  = "Accept failed : ";
   
    /** @brief Error message in case of unknown fail */
    inline constexpr const char * __error_network_undefined_TEXT  = "UNDEFINED ERROR ";

/**
 * @brief Local/Global definitons
*/

/**
 * @brief Select for correct message in case of network syscall failed
 * @param mask Bitmask for error message
 * @return pointer to errror message
*/
inline static constexpr const char * _error_message__network(uint8_t const mask)
{
    if (mask & __error_network_connect_BIT)
    {
        return __error_network_connect_TEXT;
    }
    else if (mask & __error_network_bind_BIT)
    {
        return __error_network_bind_TEXT;
    }
    else if (mask & __error_network_listen_BIT)
    {
        return __error_network_listen_TEXT;
    }
    else if (mask & __error_network_accept_BIT)
    {
        return __error_network_accept_TEXT;
    }
    else
    {
        return __error_network_undefined_TEXT;
    }
}

/**
 * @brief Class - Support error message and exiting running procces during runtim of app
*/
class MSupportError final
{
    public:
        /**
         * @brief Print error message and exit running procces
         * @param network_mask Bitmask for error message
        */
        static inline void __INIT_NETWORK_ERROR(uint8_t const network_mask) noexcept
        {
            perror(_error_message__network(network_mask));
            USERSPACE_EXIT(__error_exit_status);
        }
        static inline void __RUNTIME_NETWORK_ERROR(uint8_t const network_mask) noexcept
        {
            perror(_error_message__network(network_mask));
            // Send SIGINT signal and runs signal handler
            raise(INTERRUPT_SIGNAL);
        }

};