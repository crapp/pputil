// General purpose helper utilities for modern c++
// Copyright © 2019 Christian Rapp

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PPUTIL_HPP
#define PPUTIL_HPP

#include <sstream>
#include <string>

#ifdef __GNUC__
/**
 * @brief Simple macro to mark parameters or variables as unused
 */
#define ATTR_UNUSED __attribute__((unused))
#else
#define ATTR_UNUSED
#endif

/**
 * @brief pputil namespace
 */
namespace pputil
{
/**
 * @brief Base case
 *
 * @tparam FirsT First parameter
 * @param first
 *
 * @return
 */
template <typename FirsT>
std::string toml_stringify(const FirsT &first)
{
    return first;
}

/**
 * @brief Function to chain to toml identifier strings with dots recursively
 *
 * @tparam T
 * @tparam FirsT
 * @param first First parameter
 * @param t Paramter pack
 *
 * @return Chained string
 */
template <typename... T, typename FirsT>
std::string toml_stringify(const FirsT &first, const T &... t)
{
    return first + std::string(".") + toml_stringify(t...);
}

/**
 * @brief To string conversion using stringstream and << operator
 *
 * @param t Object o convert, must implement << operator
 *
 * @return std::string
 */
template <typename T>
inline std::string op_to_string(const T &t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

/**
 * @brief Concatenate elements to one string using a stringstream
 *
 * @tparam Args Pass your arguments here
 * @param args
 *
 * @return The concatenated string
 */
template <typename... Args>
std::string stringify(const Args &... args)
{
    std::stringstream ss;
    // maybe_unused is a c++17 feature
#if __cplusplus > 201402L
    [[maybe_unused]] int a[] = {0, ((void)(ss << args), 0)...};
#else
    ATTR_UNUSED int a[] = {0, ((void)(ss << args), 0)...};
#endif

    return ss.str();
}
} // namespace pputil

#endif /* ifndef PPUTIL_HPP */
