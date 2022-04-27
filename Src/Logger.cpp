/// \brief Epilogger
/// \authors @aurelenc
/// \file Logger.cpp

#include "Logger.hpp"
#include "LoggableException.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static std::string getSeverityColor(Logger::Severity severity)
{
    switch (severity) {
        case Logger::LOW:
            return LOGGER_COLOR_GREEN;
        case Logger::MEDIUM:
            return LOGGER_COLOR_YELLOW;
        case Logger::HIGH:
            return LOGGER_COLOR_RED;
        case Logger::CRITICAL:
            return LOGGER_COLOR_PURPLE;
        case Logger::INFO:
            return LOGGER_COLOR_CYAN;
        default:
            return LOGGER_COLOR_RESET;
    }
}

static std::string getSeverityString(Logger::Severity severity)
{
    switch (severity) {
        case Logger::Severity::LOW:
            return "LOW";
        case Logger::Severity::MEDIUM:
            return "MEDIUM";
        case Logger::Severity::HIGH:
            return "HIGH";
        case Logger::Severity::CRITICAL:
            return "CRITICAL";
        case Logger::Severity::INFO:
            return "INFO";
        default:
            return "MEDIUM";
    }
}

LoggableException Logger::log(LoggableException ex, Severity severity)
{
    std::stringstream ssColor;
    std::stringstream ss;
    std::ofstream ofLog;
    std::string severityString = getSeverityString(severity);
    std::string severityColor = getSeverityColor(severity);

    ssColor << "[LOGGER:" << severityColor << severityString << LOGGER_COLOR_RESET << "] " << severityColor << LOGGER_COLOR_BOLD << ex.getName() << LOGGER_COLOR_RESET << " >> " << LOGGER_COLOR_BOLD << ex.what() << LOGGER_COLOR_RESET << std::endl;
    ssColor << LOGGER_COLOR_RED << ">> " << LOGGER_COLOR_WHITE << LOGGER_COLOR_BOLD << ex.getFunc() << LOGGER_COLOR_RESET << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
    std::cerr << ssColor.str() << std::endl;

    try {
        ss << "[LOGGER:" << severityString << "] " << ex.getName() << " >> " << ex.what() << std::endl;
        ss << ">> " << ex.getFunc() << " (" << ex.getFile() << ":" << ex.getLine() << ")" << std::endl;
        ofLog.open("arcade.log", std::ios::app);
        ofLog << ss.str() << std::endl;
        ofLog.close();
    } catch (std::exception &e) {
        std::cerr << "Logging into 'arcade.log' file failed (" << e.what() << ")" << std::endl;
    }
    return ex;
}
