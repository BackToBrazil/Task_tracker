#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "Token.h"
namespace task_tracker{
	class Token_stream {
	public:
		Token_stream(){}
		std::vector<Token> get_tokens(const std::string&);
	private:
		std::vector<Token> m_tokens;

	};
}