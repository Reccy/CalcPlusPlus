# pragma once
#include <string>

class ParseException : public std::exception {
public:
	ParseException(std::string m = "exception!") : msg(m) {}
	~ParseException() throw() {}
	const char* what() const throw() { return msg.c_str(); }

private:
	std::string msg;
};