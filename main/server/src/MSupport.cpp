#pragma once

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
#include "../headers/MSupport.hpp"

/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

inline constexpr const char * __arg_info = "info";

inline constexpr uint8_t __arg_index = (uint8_t)1;

/**
 * @brief Local/Global definitons
*/

/**
 * @brief Member functions definitions
*/

/**
 * 
*/
void MainSupport::parse_terminal_arguments(char ** args)
{
    if (nullptr != args[__arg_index])
    {
        std::string_view argument(args[__arg_index], sizeof(args[__arg_index]));

        if (argument.empty())
        {
            _set_argument_bit(__no_name_is_set_BIT);
        }
        else if (argument == __arg_info)
        {
            _set_argument_bit(__info_is_set_BIT);
        }
        else
        {
            _set_argument_bit(__no_name_is_set_BIT);
            _term_args.argument_value.emplace(argument);
        }
    }
    else
    {
        _set_argument_bit(__no_name_is_set_BIT);
    }

}