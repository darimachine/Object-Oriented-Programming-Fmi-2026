#include <exception>
#include <string>

class DivisionByZeroException : public std::exception {
private:
    std::string message;
public:
    DivisionByZeroException() : message("Error: Division by zero!") {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};