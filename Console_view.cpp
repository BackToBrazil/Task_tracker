#include "Console_view.h"
using std::cin, std::cout, std::string;
namespace task_tracker {
	std::string task_tracker::to_string(const Token_kind& tk) {
		switch (tk)
		{
		case Token_kind::COMMAND:
			return "COMMAND";
		case Token_kind::FLAG:
			return "FLAG";
		case Token_kind::VALUE:
			return "VALUE";
		case Token_kind::TASK_NAME:
			return "TASK_NAME";
		default:
			return "UNKNOWN";
		}
	}
	std::ostream& operator<<(std::ostream& os, const Token_kind& token_kind) {
		return os << to_string(token_kind);
	}
	std::ostream& operator<<(std::ostream& os, const task_tracker::Token& token) {
		return os << '(' << token.m_kind << ')' << '('  << token.m_value << ')';
	}
	char Console_view::get_input() {
		char ch;
		cin >> ch;
		if (cin.good()) {
			return ch;
		}
		else
			throw std::runtime_error{ "input not good.\n" };
	}
	std::string Console_view::get_task_name(char terminator) {
		std::string name;
		while (true) {
			char ch = get_input();
			if (ch == terminator)
				return name;
			name += ch;
		}
	}
	Token_kind Console_view::get_kind() {
		return Token_kind::UNKOWN;
	}
	Token Console_view::get_token() {
		char ch = get_input();
		string value;
		switch (ch)
		{
		case'-':
			return Token{ Token_kind::FLAG };
			break;
		case'"':
			value = get_task_name('"');
			return Token{ Token_kind::TASK_NAME, value };
			break;
		case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
			cin.unget();
			cin >> value;
			return Token{ Token_kind::VALUE, value };
			break;
		default:
			cin.unget();
			cin >> value;
			return Token{ Token_kind::COMMAND, value };
			break;
		}
	}
}