#pragma once
namespace task_tracker {
	using namespace task_tracker;
	enum class Token_flag {
		invalid_token,
		end_program,
		add_task,
		delete_task
	};
	struct Token {
		Token_flag m_flag;
		std::string value;
	};
}
