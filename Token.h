#pragma once
#include <string>
namespace task_tracker {
	enum class Token_kind {
		invalid_token,
		task_name,
		command_flag,
		task_id,
		command_name,
	};
	struct Token {
		Token(Token_kind kind, std::string value) : m_kind{ kind }, m_value{value}{}
		Token_kind m_kind = Token_kind::invalid_token;
		std::string m_value;
	};
	std::ostream& operator<<(std::ostream&, const Token&);
}
