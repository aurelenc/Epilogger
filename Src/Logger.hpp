/// \brief LibCPPLogger
/// \authors @aurelenc
/// \file Logger.hpp
#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class LoggableException;

/// \brief Logger class to log exceptions
class Logger {
    public:
        enum Severity {
            NONE,
            LOW,
            MEDIUM,
            HIGH,
            CRITICAL,
            INFO,
            SEVERITY_ENUM_SIZE
        };
        /// \brief Deleted Constructor, this class must not be instantiated.
        Logger() = delete;
        /// \brief log the exception before throwing it
        /// \param ex the exception to log
        /// \return the exception
        static LoggableException log(LoggableException exception, Severity severity);
};

/// \brief Defines the color codes to print the exceptions in color
#define LOGGER_COLOR_RESET "\x1B[0m"
#define LOGGER_COLOR_BLACK "\x1B[30m"
#define LOGGER_COLOR_RED "\x1B[31m"
#define LOGGER_COLOR_GREEN "\x1B[32m"
#define LOGGER_COLOR_YELLOW "\x1B[33m"
#define LOGGER_COLOR_BLUE "\x1B[34m"
#define LOGGER_COLOR_PURPLE "\x1B[35m"
#define LOGGER_COLOR_CYAN "\x1B[36m"
#define LOGGER_COLOR_WHITE "\x1B[37m"
#define LOGGER_COLOR_BOLD "\x1B[1m"

#endif /* !LOGGER_HPP_ */
