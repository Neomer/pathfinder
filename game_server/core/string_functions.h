//
// Created by kir on 28.06.19.
//

#ifndef GAME_SERVER_STRING_FUNCTIONS_H
#define GAME_SERVER_STRING_FUNCTIONS_H

#include <algorithm>
#include <cctype>
#include <locale>
#include <cstring>

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

static inline const char * strrstr(const char *str, const char *needle) {
    auto needleLength = strlen(needle);
    auto strLength = strlen(str);

    for (auto idx = strLength - needleLength; idx > 0; --idx) {
        auto find = true;
        for (auto subIdx = 0; subIdx < needleLength; ++subIdx) {
            if (str[idx + subIdx] != needle[subIdx]) {
                find = false;
                break;
            }
        }
        if (find) {
            return str + idx;
        }
    }
    return nullptr;
}

#endif //GAME_SERVER_STRING_FUNCTIONS_H
