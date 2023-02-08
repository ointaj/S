#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <string>
#include <vector>
#include <cstring>

/**
 * @brief Headers for C build-in for libraries
*/

/**
 * @brief Headers for .h files
*/

/**
 * @brief Headers for .hpp files
*/

#include "../../thread/header/ThreadConfig.hpp"
/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

    enum __server_commands : uint8_t
    {
        /** @brief Print command - print you users connected to do server by given ID */
        ___sc_PRINT,
        /** @brief Print command - print you all users connected to do server  */
        ___sc_PRINT_ALL,
        /** @brief Count of command */
        ___sc_COUNT,
    };

    /** @brief String literal for command - print */
    inline constexpr const char * __arg_print = "print";
    /** @brief String literal for command - print-all */
    inline constexpr const char * __arg_print_all = "print-all";
    /** @brief Delimeter for print command */
    inline constexpr const char * __terminal_server_maintanance_delimeter = "-";

    inline constexpr uint8_t __PRINT_COMMAND_BITMASK = (1 << ___sc_PRINT);
    inline constexpr uint8_t __PRINT_ALL_COMMAND_BITMASK = (1 << ___sc_PRINT_ALL);


/**
 * @brief Local/Global definitons
*/
    /** @brief Struct saving terminal inputs by server administrator */
    struct terminal_arguments__server_maintanance final
    {
        private:
            /** @brief Raw terminal input */
            std::string _terminal_input;
            /** @brief Id's parsed from terminal input */
            std::vector<____max_supported_connection_id_type> _id; 
            /** @brief Bifield for current command type */
            uint8_t _active_command : ___sc_COUNT;

        public:
            /**
             * @brief Setter member function for input from terminal
             * @param data Rvalue reference to data from terminal - use std::move
            */
            inline void set_terminal_input(std::string && data)
            {
                _terminal_input = std::move(data);
            }
            /**
             * @brief Getter member function for reference to raw terminal input
             * @return reference to raw terminal input
            */
            inline std::string & get_ref_terminal_input()
            {
                return _terminal_input;
            }
            /**
             * @brief Getter member function for const reference to raw terminal input
             * @return const reference to raw terminal input
            */
            inline std::string const& get_const_ref_terminal_input()
            {
                return _terminal_input;
            }

            inline constexpr void set_command_bit(uint8_t const bitmask)
            {
                _active_command |= bitmask;
            }

            inline constexpr bool chcek_command_bit(uint8_t const bitmask)
            {
                return _active_command & bitmask;
            }

            inline void add_id(____max_supported_connection_id_type const id)
            {
                _id.push_back(id);
            }
    };

/** @brief Class represents main functionality for terminal inputs by server administrator */
class ServerTerminalSupport final
{
    private:
        /** @brief Instance of terminal inputs by administrator */
        terminal_arguments__server_maintanance _arguments;

    public:
        /**
         * @brief Parser for raw terminal inputs
         * @param input_data Rvalue reference for data raw data
        */
        void parse_terminal_input(std::string && input_data);

    public:
        /**
         * @brief Operator * overload for terminal input struct
         * @return reference to terminal arguments struct
        */
        inline constexpr terminal_arguments__server_maintanance & operator*()
        {
            return _arguments;
        }
        
        /**
         * @brief Operator -> overload for terminal input struct
         * @return pointer to terminal arguments struct
        */
        inline constexpr terminal_arguments__server_maintanance * operator->()
        {
            return &_arguments;
        }
};