
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
#include "../headers/MSupportTerminalServerMaintenance.hpp"

/**
 * @brief Pre-proccesor defintions
*/

/**
 * @brief Compile time checks
*/

/**
 * @brief Constant definitions
*/

/**
 * @brief Local/Global definitons
*/

/**
 * @brief Member functions definitions
*/

/**
 * 
*/
void ServerTerminalSupport::parse_terminal_input(std::string && input_data)
{
    _arguments.set_terminal_input(std::move(input_data));
    
    std::string_view view_of_data(_arguments.get_const_ref_terminal_input().c_str(),
                                  _arguments.get_const_ref_terminal_input().size());

    if (__arg_print_all == (view_of_data.substr(0,
                            std::strlen(__arg_print_all))))
    {
        _arguments.set_command_bit(__PRINT_COMMAND_BITMASK);

        bool loop_flag = true;
        std::size_t position_ofsset = 0;

        while (loop_flag)
        {
            static constexpr std::size_t offset_incement = 1;
            static constexpr int decimal_base = 10;
            auto pos_of_delimeter = view_of_data.find(__terminal_server_maintanance_delimeter, position_ofsset);
            if (std::string_view::npos != pos_of_delimeter)
            {
                position_ofsset = (pos_of_delimeter + offset_incement);
                auto second_pos_of_delimter = view_of_data.find(__terminal_server_maintanance_delimeter, position_ofsset);
                
                const auto id_substr = [second_pos_of_delimter,
                                        pos_of_delimeter,
                                        &position_ofsset,
                                        view_of_data,
                                        &loop_flag]()
                {
                    if (std::string_view::npos != second_pos_of_delimter)
                    {
                        position_ofsset = (pos_of_delimeter + offset_incement);
                        return view_of_data.substr(pos_of_delimeter,
                                                   second_pos_of_delimter + offset_incement);
                    }

                    loop_flag = false;
                    return view_of_data.substr(pos_of_delimeter);
                }();
                
                char * control_end = nullptr;
                const auto parsed_id =  std::strtol(id_substr.data(),
                                                    &control_end,
                                                    decimal_base);
                if (control_end == id_substr)
                {
                    _arguments.add_id(parsed_id);
                }
            }
            else
            {
                loop_flag = false;
            }
        }
    }
    else if (__arg_print == (view_of_data.substr(0,
                            std::strlen(__arg_print))))
    {
        _arguments.set_command_bit(__PRINT_ALL_COMMAND_BITMASK);
        
    }
    else // wrong input - do nothing // maybe add new commans later
    {

    }
}