#pragma once
#include <string>
namespace task_tracker {
	enum class Token_kind {
		COMMAND,
		TASK_ID,
		TASK_DESCRIPTION,
		TASK_STATUS,
		END_OF_FILE,
		QUIT
	};
	struct Token {
		Token(Token_kind kind) : m_kind{ kind }{}
		Token(Token_kind kind, std::string value) : m_kind{ kind }, m_value{value}{}
		Token_kind m_kind;
		std::string m_value;
	};
	std::string to_string(const Token_kind&);
	std::ostream& operator<<(std::ostream&, const Token&);
	std::ostream& operator<<(std::ostream&, const Token_kind&);
	std::istream& operator>>(std::istream&, Token&);
}