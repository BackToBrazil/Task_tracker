#include "Console_view.h"
using std::cin, std::cout, std::string;
namespace task_tracker {
	std::string task_tracker::to_string(const Token_kind& tk) {
		switch (tk)
		{
		
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
	std::string Console_view::get_command(char t1, char t2) {
		std::string name;
		while (true) {
			char ch = get_input();
			if (ch == t1 || t2)
				return name;
			name += ch;
		}
	}
	Token Console_view::get_token() {
		char ch = get_input();
		string value;
		switch (ch)
		{
		
		}
	}
}