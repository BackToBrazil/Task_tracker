#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
namespace parser_utils {
	// TODO: create an overload for expect_string() to not make the '"'s ignore hardwired.

	void expect_string(std::istream&, std::string);	// verify if the next set of chars match the string passed as argument.
	void expect_char(std::istream&, char);		// verify if the next char is the expected one and waste it
}