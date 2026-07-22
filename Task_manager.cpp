#include "Task_manager.h"
#include "Token.h"
namespace task_tracker {
	std::ostream& operator<<(std::ostream& os, const status& status) {
		switch (status)
		{
		case status::TODO:
			return os << "TODO";
		case status::IN_PROGRESS:
			return os << "in_progress";
		case status::DONE:
			return os << "done";
		default:
			return os << "status not defined yet";
		}
	}
	std::istream& operator>>(std::istream& is, status& status)
	{
		std::string ss;
		char ch;
		while (true) {
			is >> ch;
			if (!isalpha(ch)) {
				is.unget();
				break;
			}
			ss += ch;
		}
		if (ss == "todo" || ss == "TODO") {
			status = status::TODO;
			return is;
		}
		if (ss == "in-progress" || ss == "in_progress") {
			status = status::IN_PROGRESS;
			return is;
		}
		if (ss == "done") {
			status = status::DONE;
			return is;
		}
		status = status::UNKOWN;
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const task_tracker::Date& date) {
		return os << '(' << date.m_day << '/' << date.m_month << '/' << date.m_year << ')';
	}
	std::istream& operator>>(std::istream& is, Date& date)
	{
		int day = -1;
		std::string month = "janeiro";
		int year = 0001;
		while (is.good()) {
			parser_utils::expect_char(is, '(');
			is >> day;
			parser_utils::expect_char(is, '/');
			std::getline(is, month, '/');
			is >> year;
			break;
		}
		date = Date{ day, month, year };
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const task_tracker::Task& task) {
		return os << "Task ID: " << task.m_id << "\nTask Description: " << task.m_description << "\nTask Creation Date: " << task.m_created_at << "\nTask Update Date: " << task.m_updated_at <<
			"\nTask STATUS: " << task.m_status << '\n';
	}
	void Task_manager::add_task(const Command& command) {
		// verify if id doesnt already exists
		// verify if date is valid
		int id = m_task_list.size() + 1;
		Date date{ 15, "july", 2026 };
		Task my_task{ id, command.argument, date};
		m_task_list.push_back(my_task);
	}
}