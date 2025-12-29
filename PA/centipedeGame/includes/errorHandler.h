/**
 * @file errorHandler.h
 * @author Balin Becker, Ian Codding II, Roman Salazar
 * @brief For error analysis
 * @version 0.1
 * @date 2025-10-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H
#include <iostream>
#include <stdexcept>

class ResourceError : public std::runtime_error {
public:
    ResourceError(const std::string& msg) : std::runtime_error(msg) {}
};

inline void logError(const std::string& context, const std::string& error) {
    std::cerr << "[ERROR] " << context << ": " << error << std::endl;
}

#endif