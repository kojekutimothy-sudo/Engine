#pragma once

#include <string>
#include <string_view>

constexpr const char* LOG_DEFAULT_TEXT = "<LOG>\n\n";

class Log {
    public:
        Log() : _log(LOG_DEFAULT_TEXT), _logs(0) {};

        void add(std::string_view str, bool nl = true);
        void clear();

        const char* get() const { return _log.c_str(); }
        int getNumLogs() const { return _logs; }
    private:
        std::string _log;
        uint32_t _logs;
};