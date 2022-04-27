/// \brief Epilogger
/// \authors @aurelenc
/// \file LoggableException.hpp

#ifndef LIBCPPLOGGER_LOGGABLEXCEPTION_HPP
#define LIBCPPLOGGER_LOGGABLEXCEPTION_HPP

#include "Logger.hpp"
#include <exception>
#include <string>
#include <sstream>
#include <functional>

/// \Defines the params taken by the exceptions in addition to the "what" message
#define EX_PARAMS __PRETTY_FUNCTION__, __LINE__, __FILE__

/// \brief The template to specify the exception to throw or/and log
template<class T>
/// \brief The 'EX' class used to log exceptions when throwing them
/// \tparam T The exception to throw
/// \param what The 'what' message of the exception
/// \param severity The Logger::Severity to log (NONE, INFO, LOW, MEDIUM, HIGH, CRITICAL)
class EX : public T
{
    public:
        EX (const std::string &what, Logger::Severity severity) : T(what, EX_PARAMS)
        {
            if (severity != Logger::Severity::NONE)
                Logger::log(*this, severity);
        }
};

/// \brief Base exception class for all exceptions in the project
class LoggableException : public std::exception {
    public:
        /// \brief DO NOT USE THIS CONSTRUCTOR, PLEASE USE THE EX CLASS
        /// \param what The description of the exception
        /// \param func The function where the exception is thrown
        /// \param file The file where the exception is thrown
        /// \param line The line where the exception is thrown
        explicit LoggableException(std::string const &what, std::string const &func, int const &line, std::string const &file);
        /// \brief returns the description of the exception
        /// \return the description of the exception
        [[nodiscard]] const char *what() const noexcept override;
        /// \brief returns where the exception is thrown
        /// \return the where the exception has been thrown
        [[nodiscard]] const std::string &where() const noexcept;
        /// \brief returns the function where the exception is thrown
        /// \return the function where the exception is thrown
        [[nodiscard]] const std::string &getFunc() const noexcept;
        /// \brief returns the file where the exception is thrown
        /// \return the file where the exception is thrown
        [[nodiscard]] const std::string &getFile() const noexcept;
        /// \brief returns the line where the exception is thrown
        /// \return the line where the exception is thrown
        [[nodiscard]] const int &getLine() const noexcept;
        /// \brief returns the name of the exception
        /// \return the name of the exception
        [[nodiscard]] const std::string &getName() const noexcept;

    protected:
        std::string _name;
        std::string _what;
        std::string _where;
        std::string _func;
        std::string _file;
        int _line;

    private:
};

#endif /* !LIBCPPLOGGER_LOGGABLEXCEPTION_HPP */
