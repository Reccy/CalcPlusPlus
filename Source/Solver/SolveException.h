# pragma once
#include <string>

class SolveException : public std::exception {
public:
	SolveException(std::string m = "exception!") : msg(m) {}
	~SolveException() noexcept {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};