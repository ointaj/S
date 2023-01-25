#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <string_view>
#include <algorithm>
#include <optional>

/**
 * @brief Headers for C build-in for libraries
*/

#include <stdint.h>

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
    /** @brief Maximal size of bitmap represents arguments*/
    inline constexpr uint8_t __bitmap_args_off     = (uint8_t)3;
    
    inline constexpr uint8_t __name_is_set_BIT     = (1 << 0);
    inline constexpr uint8_t __info_is_set_BIT     = (1 << 1);
    inline constexpr uint8_t __no_name_is_set_BIT  = (1 << 2);

/**
 * @brief Local/Global definitons
*/
    struct terminal_arguments
    {
        std::optional<std::string> argument_value;
        uint8_t argument_active_bit : __bitmap_args_off;

        inline constexpr bool check_arg_bit(uint8_t mask)
        {
            return (argument_active_bit & mask);
        }
    };


/**
 * @brief Class - Support basic functionality for outpusts in terminal duting inicializations
*/
class MainSupportTerminal final
{
    private:
        /** @brief */
        terminal_arguments _term_args;

    private:
        /**
         * @brief Main function starting server side
         * @param argc Count of arguments pass to main function from terminal
         * @return Imlicite value for main function in linux envrioment
        */
        inline constexpr void _set_argument_bit(uint8_t mask)
        {
            _term_args.argument_active_bit |= mask;
        }

    public:
        /**
         * @brief Main function starting server side
         * @param argc Count of arguments pass to main function from terminal
         * @param args Pointer to charachter array from terminal
        */
        void parse_terminal_arguments(char ** args);

        /**
         * @brief Main function starting server side
         * @return Imlicite value for main function in linux envrioment
        */
        inline terminal_arguments && get_terminal_args() { return std::move(_term_args); }

};