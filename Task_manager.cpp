#include "Task_manager.h"
#include "Token.h"
namespace task_tracker {
	std::ostream& operator<<(std::ostream& os, const status& status) {
		switch (status)
		{
		case status::todo:
			return os << "TODO";
		case status::in_progress:
			return os << "in_progress";
		case status::done:
			return os << "done";
		default:
			return os << "status not defined yet";
		}
	}
	std::ostream& operator<<(std::ostream& os, const task_tracker::Date& date) {
		return os << '(' << date.day << '/' << date.month << '/' << date.year << ')';
	}
	std::ostream& operator<<(std::ostream& os, const task_tracker::Task& task) {
		return os << "Task ID: " << task.m_id << "\nTask Description: " << task.m_description << "\nTask Creation Date: " << task.m_created_at << "\nTask Update Date: " << task.m_updated_at <<
			"\nTask STATUS: " << task.m_status << '\n';
	}
	void task_tracker::Task_manager::add_task(std::string description) {
		// verify if id doesnt already exists
		// verify if date is valid
		int list_size = m_task_list.size()+1;
		m_task_list.push_back(Task{ list_size, description  ,Date{02,"July",2026} });
	}
}