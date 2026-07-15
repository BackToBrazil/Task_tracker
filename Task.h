#pragma once
#include <string>
#include <iostream>
#include "Date.h"
#include "Token.h"
namespace task_tracker {
	const std::vector<std::string> all_Task_status{ "TODO", "todo", "IN-PROGRESS", "in-progress", "DONE", "done"};
	enum class status {
		TODO,
		IN_PROGRESS,
		DONE
	};
	struct Task {
		// simple data structure for tasks.
		Task(int id, std::string description, Date created_at) : m_id{ id }, m_description{description},
			m_created_at{ created_at }, m_updated_at{created_at} {}
		Task(int id, Date created_at) : m_id{ id }, m_created_at{ created_at }, m_updated_at{created_at} {}
		int m_id;
		std::string m_description = "no description.";
		status m_status = status::TODO;
		Date m_created_at;
		Date m_updated_at;
	};
	std::ostream& operator<<(std::ostream&, const Task& task);
	std::ostream& operator<<(std::ostream&, const status& status);
}