/*
 * Copyright 2019 Equal Games
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#include <utility>
#include <vector>

/**
 * @defgroup str String
 * @ingroup helpers
 * @brief String functions
 */

namespace eq::str {

/**
 * @ingroup str
 * @brief
 *
 * @param text std::string&
 * @param search const std::string&
 * @param replace const std::string&
 */
void replace(std::string &text, const std::string &search, const std::string &replace);

/**
 * @ingroup str
 * @brief
 *
 * @param path const std::string&
 * @param with_extension bool
 * @return std::string
 */
std::string filename(const std::string &path, bool with_extension = true);

/**
 * @ingroup str
 * @brief Transform wide-string in normal string
 *
 * @param in const wchar_t*
 * @return std::string
 */
std::string wchar_to_utf8(const wchar_t *in);

/**
 * @ingroup str
 * @brief Transform normal string in wide-string
 *
 * @param in const char*
 * @return std::wstring
 */
std::wstring utf8_to_wchar(const char *in);

/**
 * @ingroup str
 * @brief trim from start (in place)
 *
 * @param s std::string&
 */
void ltrim(std::string &s);

/**
 * @ingroup str
 * @brief trim from end (in place)
 *
 * @param s std::string&
 */
void rtrim(std::string &s);

/**
 * @ingroup str
 * @brief trim from both ends (in place)
 *
 * @param s std::string&
 */
void trim(std::string &s);

/**
 * @ingroup str
 * @brief trim from start (copying)
 *
 * @param s std::string
 * @return std::string
 */
std::string ltrim_copy(std::string s);

/**
 * @ingroup str
 * @brief trim from end (copying)
 *
 * @param s
 * @return std::string
 */
std::string rtrim_copy(std::string s);

/**
 * @ingroup str
 * @brief trim from both ends (copying)
 *
 * @param s std::string
 * @return std::string
 */
std::string trim_copy(std::string s);

/**
 * @ingroup str
 * @brief Split string by delimiter
 *
 * @param text const std::string&
 * @param delimiter char
 * @return std::vector<std::string>
 */
std::vector<std::string> split(const std::string &text, char delimiter);

/**
 * @ingroup str
 * @brief Split string in two values
 *
 * @param text const std::string&
 * @param delimiter char
 * @param remove_spaces bool
 * @return std::pair<std::string, std::string>
 */
std::pair<std::string, std::string> split_pair(const std::string &text, char delimiter, bool remove_spaces = true);

} // namespace eq::str
