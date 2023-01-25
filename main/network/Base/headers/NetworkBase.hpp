#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

/**
 * @brief Headers for C build-in for libraries
*/
#include <sys/socket.h>
#include <unistd.h>
/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../../../support/headers/MSupportError.hpp"

/**
 * @brief Pre-proccesor defintions
*/

#define RES_NETWORK_CHECK_SYS_CALL( res ) if( __syscall_error == res ) { MSupportError::__NETWORK_ERROR(__error_network_connect_BIT); } 

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    /** @brief */
    inline constexpr int __SOCKET_DOMAIN__IPV4 = AF_INET;

    /** @brief */
    inline constexpr int __SOCKED_TYPE = SOCK_STREAM;

    /** @brief */
    inline constexpr int __PROTOCOL__DEFAULT =-0;

/**
 * @brief Local/Global definitons
*/

/**
 * @brief Main function starting server side
 * @param argc Count of arguments pass to main function from terminal
 * @param args Pointer to charachter array from terminal
 * @return Imlicite value for main function in linux envrioment
*/

/**
 * @brief Base class for networking
*/
class iNetworkBase final
{
    private:

    protected:
        /** @brief */
        int __client_socket_fd;
    
    public:
        /** @brief */
        iNetworkBase() : __client_socket_fd(0)
        {
            __client_socket_fd = socket(__SOCKET_DOMAIN__IPV4, __SOCKED_TYPE, __PROTOCOL__DEFAULT);
            RES_NETWORK_CHECK_SYS_CALL(__client_socket_fd);
        }

        /** @brief */
        virtual ~iNetworkBase()
        {
            close(__client_socket_fd);
        }

    public:
        /**
         * @brief Main function starting server side
         * @return Imlicite value for main function in linux envrioment
        */
        virtual int get_client_socket_fd() = 0;

        /**
         * @brief Main function starting server side
         * @return Imlicite value for main function in linux envrioment
        */
        virtual int & set_client_socket_fd() = 0;
};