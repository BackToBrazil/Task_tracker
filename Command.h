#pragma once
#include <string>
#include <iostream>
namespace task_tracker {
	enum class Command_type {
		add,
		delete_,
		update,
		mark_in_progress,
		mark_done,
		list,
		unknown,
	};
	struct Command {
		Command_type command_type;
		std::string argument;
		Command(Command_type ct, std::string arg) : command_type{ ct }, argument{ arg }{}
	};
	Command_type string_to_command(const std::string&);
	std::ostream& operator<<(std::ostream&, Command&);
	std::ostream& operator<<(std::ostream&, Command_type&);
}