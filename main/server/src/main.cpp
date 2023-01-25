/**
 * @brief Headers for C++ build-in for libraries
*/
#include <iostream>

/**
 * @brief Headers for C build-in for libraries
*/

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../../support/headers/MSupportTerminal.hpp"
#include "../../network/Base/headers/NetworkBase.hpp"

/**
 * @brief Pre-proccesor defintions
*/
    /** @brief OS this app supports **/
    #define OS_SUPPORT__COMPILER_VALUE __linux__

    /** @brief Version of C++ standart this app only supports **/
    #define CPP_STANDART_VERSION__COMPILER_VALUE 201703L

    /** @brief Current version of C++ standart durring build time**/
    #define CURRENT_CPP_STANDART_VERSION__COMPILER_VALUE __cplusplus

    /** @brief Check for current type of compiler **/
    #define GCC__COMPILER_CHECK (defined(__GNUC__) && !defined(__clang__)  && !defined(_MSC_VER)) 

    /** @brief Check for validity of current version of C++ standart **/
    #define CPP_STANDART_VERSION__COMPILER_CHECK (CURRENT_CPP_STANDART_VERSION__COMPILER_VALUE != CPP_STANDART_VERSION__COMPILER_VALUE)
/**
 * @brief Compile time checks
*/
    #if OS_SUPPORT__COMPILER_VALUE
        #ifdef GCC__COMPILER_CHECK
            #if CPP_STANDART_VERSION__COMPILER_CHECK
                #error "WRONG VERSION OF C++ STANDART HAS BEEN CHOOSED"
            #endif // CPP_STANDART_VERSION__COMPILER_CHECK
        #else
            #error "WRONG COMPILER FOR THIS APP - ONLY GCC IS POSSIBLE"
        #endif //GCC__COMPILER_CHECK
    #else
        #error "WRONG OS - ONLY RUN UNDER LINUX DISTRUBTIONS (Ubuntu, Debian..)"
    #endif // OS_SUPPORT__COMPILER_VALUE

/**
 * @brief Main function starting server side
 * @param argc Count of arguments pass to main function from terminal
 * @param args Pointer to charachter array from terminal
 * @return Imlicite value for main function in linux envrioment
*/
int main(int argc,
         char ** args)
{
    (void)argc;
    terminal_arguments full_terminal_argumensts;
    {
        MainSupportTerminal a;
        a.parse_terminal_arguments(args);
        full_terminal_argumensts = std::move(a.get_terminal_args());
    }

    if (full_terminal_argumensts.check_arg_bit(__info_is_set_BIT))
    {

    }
    else if (full_terminal_argumensts.check_arg_bit(__no_name_is_set_BIT))
    {

    }
    else // full_terminal_argumensts.check_arg_bit(__name_is_set_BIT)
    {
        
    }

    return 0;
}