#pragma once
#include <string>
namespace task_tracker {
	enum class Token_kind {
		COMMAND,
		VALUE,
		FLAG,
		TASK_NAME,
		UNKOWN
	};
	struct Token {
		Token(Token_kind kind) : m_kind{ kind }{}
		Token(Token_kind kind, std::string value) : m_kind{ kind }, m_value{value}{}
		Token_kind m_kind;
		std::string m_value;
	};
	std::ostream& operator<<(std::ostream&, const Token&);
}
