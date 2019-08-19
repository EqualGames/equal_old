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
#include <equal/core/logger.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/string.hpp>
#include <filesystem>

namespace eq::str {

void replace(std::string &text, const std::string &search, const std::string &replace) {
  size_t f = text.find(search);
  text = text.replace(f, f + search.size(), replace);
}

std::string filename(const std::string &path, bool with_extension) {
  try {
    std::filesystem::path p{path};

    if (!std::filesystem::exists(p)) {
      EQ_THROW("Path not found");
    }

    if (with_extension) {
      return p.filename().string();
    } else {
      std::string name{p.filename()};
      std::string ext{p.extension()};
      str::replace(name, ext, "");
      return name;
    }
  } catch (...) {
    EQ_THROW("Failed to read path");
  }
}

void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
}

void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
}

void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}

std::string ltrim_copy(std::string s) {
  ltrim(s);
  return s;
}

std::string rtrim_copy(std::string s) {
  rtrim(s);
  return s;
}

std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

std::vector<std::string> split(const std::string &text, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(text);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

std::pair<std::string, std::string> split_pair(const std::string &text, char delimiter, bool remove_spaces) {
  std::string_view v{text};

  if (v.find(delimiter) == v.npos) {
    if (remove_spaces) {
      return std::make_pair(trim_copy(std::string(v)), "");
    } else {
      return std::make_pair(text, "");
    }
  }

  std::string_view a = v.substr(0, v.find_first_of(delimiter));
  std::string_view b = v.substr(v.find_first_of(delimiter) + 1, v.length());

  if (remove_spaces) {
    return std::make_pair(trim_copy(std::string(a)), trim_copy(std::string(b)));
  } else {
    return std::make_pair(std::string(a), std::string(b));
  }
}

std::string wchar_to_utf8(const wchar_t *in) {
  std::string out;
  unsigned int codepoint = 0;
  for (; *in != 0; ++in) {
    if (*in >= 0xd800 && *in <= 0xdbff)
      codepoint = ((*in - 0xd800) << 10) + 0x10000;
    else {
      if (*in >= 0xdc00 && *in <= 0xdfff)
        codepoint |= *in - 0xdc00;
      else
        codepoint = *in;

      if (codepoint <= 0x7f)
        out.append(1, static_cast<char>(codepoint));
      else if (codepoint <= 0x7ff) {
        out.append(1, static_cast<char>(0xc0 | ((codepoint >> 6) & 0x1f)));
        out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
      } else if (codepoint <= 0xffff) {
        out.append(1, static_cast<char>(0xe0 | ((codepoint >> 12) & 0x0f)));
        out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
      } else {
        out.append(1, static_cast<char>(0xf0 | ((codepoint >> 18) & 0x07)));
        out.append(1, static_cast<char>(0x80 | ((codepoint >> 12) & 0x3f)));
        out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
      }
      codepoint = 0;
    }
  }
  return out;
}

std::wstring utf8_to_wchar(const char *in) {
  std::wstring out;
  unsigned int codepoint = 0;
  while (*in != 0) {
    unsigned char ch = static_cast<unsigned char>(*in);
    if (ch <= 0x7f)
      codepoint = ch;
    else if (ch <= 0xbf)
      codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf)
      codepoint = ch & 0x1f;
    else if (ch <= 0xef)
      codepoint = ch & 0x0f;
    else
      codepoint = ch & 0x07;
    ++in;
    if (((*in & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(wchar_t) > 2)
        out.append(1, static_cast<wchar_t>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<wchar_t>(0xd800 + (codepoint >> 10)));
        out.append(1, static_cast<wchar_t>(0xdc00 + (codepoint & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<wchar_t>(codepoint));
    }
  }
  return out;
}

} // namespace eq::str
