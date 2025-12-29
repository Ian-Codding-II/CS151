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