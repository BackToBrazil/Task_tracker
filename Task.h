#pragma once
#include <string>

namespace task_tracker {
	enum class status {
		todo,
		in_progress,
		done
	};

	struct Task {
		// simple data structure for tasks.
		Task(int id, std::string description, int created_at) : m_id{ id }, m_description{description},
			m_created_at{ created_at }, m_updated_at{created_at} {}
		Task(int id, int created_at) : m_id{ id }, m_created_at{ created_at }, m_updated_at{created_at} {}
		int m_id;
		std::string m_description = "no description.";
		status m_status = status::todo;
		int m_created_at;
		int m_updated_at;
	};
}