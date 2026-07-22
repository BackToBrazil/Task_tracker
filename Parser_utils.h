#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
namespace parser_utils {
	void expect_string(std::ifstream&, std::string);	// verify if the next set of chars match the string passed as argument.
	void expect_char(std::ifstream&, char);		// verify if the next char is the expected one and waste it
}