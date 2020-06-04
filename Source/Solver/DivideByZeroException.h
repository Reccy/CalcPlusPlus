# pragma once
#include <string>

class DivideByZeroException : public std::exception {
public:
	DivideByZeroException(std::string m = "exception!") : msg(m) {}
	~DivideByZeroException() noexcept {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};