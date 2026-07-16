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
	std::ostream& operator<<(std::ostream& os, const task_tracker::Date& date) {
		return os << '(' << date.m_day << '/' << date.m_month << '/' << date.m_year << ')';
	}
	std::istream& operator>>(std::istream& is, Date& date)
	{
		char ch1, day, ch2, ch4, year, ch5;
		std::string month;
		is >> ch1 >> day >> ch2 >> month >> ch4 >> year >> ch5;
		if (!is)
			return is;
		if (ch1 != '(' || ch2 != '/' || ch4 != '/' || ch5 != ')') {
			is.clear(std::ios::failbit);
			return is;
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