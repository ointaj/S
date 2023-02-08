#pragma once

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

