#include "Parser_utils.h"
namespace parser_utils {
	void parser_utils::expect_string(std::istream& ifs, std::string word)
	{
		std::string temp;
		char ch = 0;
		expect_char(ifs, '"');
		if (std::getline(ifs, temp, '"')) {
			if (temp == word) {
				//std::cout << "expect_string successful: " + temp + '\n';
				return;
			}
			else
				throw std::runtime_error{ "expected '" + word + " but caught '" + temp + "'" };
		}
		throw std::runtime_error{ "could not read '" + word + "'" };
	}
	void parser_utils::expect_char(std::istream& ifs, char ch)
	{
		char temp = ifs.peek();
		if (isspace(temp))
			ifs.ignore();
		if (ifs.get(temp)) {
			if (temp != ch)
				throw std::runtime_error{ "expected '" + std::string(1,ch) + "' but caught '" + std::string(1,temp) + "'" };
		}
		else {
			throw std::runtime_error{ "could not read '" + std::string(1,ch) + "'" };
		}
	}
}