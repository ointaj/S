#pragma once

/**
 * @brief Headers for C++ build-in for libraries
*/

#include <iostream>
#include <vector>
#include <string_view>
#include <type_traits>


/**
 * @brief Headers for C build-in for libraries
*/

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

namespace IO
{
    using ___all_clients =  std::vector<std::string_view>;
    using ___clients     =  std::vector<std::pair<____user_id_type, std::string_view>>;
}; // IO

inline constexpr char ___terminal_ouput_delimeter = '|';
inline constexpr char ___terminal_ouput_new_line = '\n';


/**
 * @brief Local/Global definitons
*/

class MSupportIO final
{
    private:
    public:
        template<typename T>
        static std::enable_if_t<std::is_same_v<T, IO::___all_clients>> 
        terminal_ouput_clients(T const& data)
        {
            (void)data;
        }
        template<typename T>
        static std::enable_if_t<std::is_same_v<T, IO::___clients>>
        terminal_ouput_clients(T const& data)
        {
            (void)data;
        }
};