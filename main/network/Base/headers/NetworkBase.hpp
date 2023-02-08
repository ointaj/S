#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <vector>

/**
 * @brief Headers for C build-in for libraries
*/
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../../../support/headers/MSupportError.hpp"
#include "../../../thread/header/ThreadConfig.hpp"

/**
 * @brief Pre-proccesor defintions
*/
    /** @brief Macro for handling result */
    #define RES_NETWORK_CHECK_SYS_CALL( res, error_bit_mas ) if( __syscall_error == res ) { MSupportError::__INIT_NETWORK_ERROR(error_bit_mas); } 

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    /** @brief Domain type for connection - ipv4 */
    inline constexpr int __SOCKET_DOMAIN__IPV4 = AF_INET;

    /** @brief Socket type - basic socket stream */
    inline constexpr int __SOCKED_TYPE = SOCK_STREAM;

    /** @brief Default protocol value - let system choose protocol */
    inline constexpr int __PROTOCOL__DEFAULT = 0;

    /** @brief Default port value */
    inline constexpr int ___PORT_VALUE__DEFAULT = 10000;

/**
 * @brief Local/Global definitons
*/

struct socket_info final
{
    /** @brief Socket description */
    struct sockaddr_in socket_info;
    /** @brief File-descriptor of current socket */
    int socket_fd;
};

/**
 * @brief Base class for networking
*/
class iNetworkBase
{
    private:
    protected:
        socket_info __socket_info;

    public:
        /** @brief Constructor - initialize network connection */
        iNetworkBase()
        {
            // Opening socket
            __socket_info.socket_fd = socket(__SOCKET_DOMAIN__IPV4, __SOCKED_TYPE, __PROTOCOL__DEFAULT);
            // Checking return value of syscall
            RES_NETWORK_CHECK_SYS_CALL(__socket_info.socket_fd, __error_network_connect_BIT);
            
            __socket_info.socket_info.sin_family = __SOCKET_DOMAIN__IPV4;
        	__socket_info.socket_info.sin_port = htons(___PORT_VALUE__DEFAULT);
	        __socket_info.socket_info.sin_addr.s_addr = INADDR_ANY;
    	    bzero(&__socket_info.socket_info.sin_zero, 0);
        }

        /** @brief Destructor - uninitiliazed network connection*/
        virtual ~iNetworkBase()
        {
            // Closing socket - file descriptor
            close(__socket_info.socket_fd);
        }

    public:
        /**
         * @brief Getter for socket file-descriptor
         * @return copy of file descriptor
        */
        inline constexpr int get_server_socket_fd()
        {
            return __socket_info.socket_fd;
        }

    public:
        virtual void init_signal() = 0;
};
