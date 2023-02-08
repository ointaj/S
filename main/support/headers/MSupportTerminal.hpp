#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <string_view>
#include <algorithm>
#include <optional>
#include <utility>

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
    /** @brief Maximal size of bitmap represents arguments */
    inline constexpr uint8_t      __bitmap_args_off_client_site     = (uint8_t)3;
    inline constexpr uint8_t      __bitmap_args_off_server_site     = (uint8_t)5;
    
    inline constexpr uint8_t      __name_is_set_BIT     = (1 << 0);
    inline constexpr uint8_t      __info_is_set_BIT     = (1 << 1);
    inline constexpr uint8_t      __no_name_is_set_BIT  = (1 << 2);

    inline constexpr const char * __arg_info = "info";
    
    inline constexpr uint8_t      __arg_index = (uint8_t)1;


/**
 * @brief Local/Global definitons
*/  
    struct terminal_arguments__server_site final
    {
        public:
            std::pair<std::optional<std::string>,
                      std::optional<std::string>> arguments;

            uint8_t argument_active_bit : __bitmap_args_off_server_site;

        public:
            inline constexpr bool check_arg_bit(uint8_t mask)
            {
                return (argument_active_bit & mask);
            }

            /**
             * @brief
             * @param
            */
            inline constexpr void set_argument_bit(uint8_t mask)
            {
                argument_active_bit |= mask;
            }
    };

    struct terminal_arguments__client_site final
    {
        public:
            std::optional<std::string> argument_value;
            uint8_t argument_active_bit : __bitmap_args_off_client_site;

        public:
            inline constexpr bool check_arg_bit(uint8_t mask)
            {
                return (argument_active_bit & mask);
            }
           
            /**
             * @brief 
             * @param 
             * @return 
            */
            inline constexpr void set_argument_bit(uint8_t mask)
            {
                argument_active_bit |= mask;
            }
    };

/**
 * @brief Class - Support basic functionality for outpusts in terminal duting inicializations
*/
template<typename _TERMINAL_ARGUMENTS_,
         typename = typename 
         std::enable_if_t<std::is_same_v<terminal_arguments__server_site, _TERMINAL_ARGUMENTS_>
                          || std::is_same_v<terminal_arguments__client_site, _TERMINAL_ARGUMENTS_>>>
class MainSupportTerminal final
{
    private:
        /** @brief */
        _TERMINAL_ARGUMENTS_ _term_args;
    
    public:
        /**
         * @brief Main function starting server side
         * @param args Pointer to charachter array from terminal
        */
        constexpr void parse_terminal_arguments(char ** args)
        {
          if constexpr (std::is_same_v<_TERMINAL_ARGUMENTS_, terminal_arguments__server_site>)
          {
            uint8_t index = __arg_index;
            while (nullptr != args[index])
            {
                std::string_view argument(args[index], sizeof(args[index]));
                if (argument.empty())
                {
                    _term_args.set_argument_bit(__no_name_is_set_BIT);
                    break;
                }
                else if (argument == __arg_info)
                {
                    _term_args.set_argument_bit(__info_is_set_BIT);
                }
                else
                {
                    // _term_args.set_argument_bit(__name_is_set_BIT);
                    // _term_args.argument_value.emplace(argument);
                }
                ++index;
            }
            // If terminal argumets were empty, so no iteration happend
            if (__arg_index == index)
            {
                _term_args.set_argument_bit(__no_name_is_set_BIT);
            }
          }
          else
          {
            if (nullptr != args[__arg_index])
            {
                std::string_view argument(args[__arg_index], sizeof(args[__arg_index]));

                if (argument.empty())
                {
                    _term_args.set_argument_bit(__no_name_is_set_BIT);
                }
                else if (argument == __arg_info)
                {
                    _term_args.set_argument_bit(__info_is_set_BIT);
                }
                else
                {
                    _term_args.set_argument_bit(__name_is_set_BIT);
                    _term_args.argument_value.emplace(argument);
                }
            }
            else
            {
                _term_args.set_argument_bit(__no_name_is_set_BIT);
            }
          }
        }
        
        /**
         * @brief 
         * @return 
        */
        inline _TERMINAL_ARGUMENTS_ && get_terminal_args() { return std::move(_term_args); }
};
