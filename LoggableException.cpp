/// \brief LibCPPLogger
/// \authors @aurelenc
/// \file LoggableException.cpp

#include "LoggableException.hpp"
#include "Logger.hpp"
#include <sstream>

LoggableException::LoggableException(std::string const &what, std::string const &func, int const &line, std::string const &file) : _name("LoggableException")
{
    std::stringstream ss;

    _what = what;
    _func = func;
    _line = line;
    _file = file;

    ss << func << " (" << file << ":" << line << ")";
    _where = ss.str();
}

const char *LoggableException::what() const noexcept
{
    return _what.c_str();
}

const std::string &LoggableException::where() const noexcept
{
    return _where;
}

const std::string &LoggableException::getFunc() const noexcept
{
    return _func;
}

const std::string &LoggableException::getFile() const noexcept
{
    return _file;
}

const int &LoggableException::getLine() const noexcept
{
    return _line;
}

const std::string &LoggableException::getName() const noexcept
{
    return _name;
}
