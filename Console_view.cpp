#include "Console_view.h"
using std::cin, std::cout, std::string;
namespace task_tracker {
	std::ostream& operator<<(std::ostream& os, const task_tracker::Token& token) {
		return os << '('  << token.m_value << ')';
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
		char ch = get_input();
		if (ch == '"') {
			return Token_kind::task_name;
		}
		else if (ch == '-') {
			return Token_kind::command_flag;
		}
		else if (isalnum(ch)) {
			return Token_kind::task_id;
		}
		else if(isdigit(ch)){
			return Token_kind::command_name;
		}
		else {
			throw std::runtime_error{ "input not good.\n" };
		}
	}
	Token Console_view::get_token() {
		Token_kind kind = get_kind();
		switch (kind)
		{
		case task_tracker::Token_kind::invalid_token:
			throw std::runtime_error{ "input not good.\n" };
			break;
		case task_tracker::Token_kind::task_name:
			return Token{kind, get_task_name('"') };
		case task_tracker::Token_kind::command_flag:
			break;
		case task_tracker::Token_kind::task_id:
			break;
		case task_tracker::Token_kind::command_name:
			// get_command();
			break;
		default:
			throw std::runtime_error{ "something went wrong!\n" };
			break;
		}
	}
}