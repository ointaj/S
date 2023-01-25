#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

/**
 * @brief Headers for C build-in for libraries
*/

#include <string.h>
#include <errno.h>

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

/**
 * @brief Pre-proccesor defintions
*/

    #define USERSPACE_EXIT(v) exit(v)
    #define KERNEL_EXIT _exit()

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    inline constexpr int __error_exit_status         = -1;

    inline constexpr int __syscall_error             = __error_exit_status;

    inline constexpr uint8_t __error_network_connect_BIT = uint8_t(1 << 0);
    inline constexpr uint8_t __error_network_bind_BIT    = uint8_t(1 << 1);
    inline constexpr uint8_t __error_network_listen_BIT  = uint8_t(1 << 2);
    inline constexpr uint8_t __error_network_accept_BIT  = uint8_t(1 << 3);

    inline constexpr const char * __error_network_connect_TEXT = "Connnect failed : ";
    inline constexpr const char * __error_network_bind_TEXT    = "Bind failed : ";
    inline constexpr const char * __error_network_listen_TEXT  = "Listen failed : ";
    inline constexpr const char * __error_network_accept_TEXT  = "Accept failed : ";

    inline constexpr const char * __error_network_undefined_TEXT  = "UNDEFINED ERROR ";


/**
 * @brief Local/Global definitons
*/

inline static constexpr const char * _error_message__network(uint8_t mask)
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
 * @brief Class - Support basic functionality for outpusts in terminal duting inicializations
*/
class MSupportError final
{
    public:
        static inline void __NETWORK_ERROR(uint8_t network_mask) noexcept
        {
            perror(_error_message__network(network_mask));
            USERSPACE_EXIT(__error_exit_status);
        }

};