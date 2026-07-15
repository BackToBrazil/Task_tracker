#include "Command.h"
#include <stdexcept>
namespace task_tracker {
	Command_type task_tracker::string_to_command(const std::string& word)
	{
		if (word == "add")
			return Command_type::add;
		if (word == "delete")
			return Command_type::delete_;
		if (word == "update")
			return Command_type::update;
		if (word == "mark_in_progress")
			return Command_type::mark_in_progress;
		if (word == "mark_done")
			return Command_type::mark_done;
		if (word == "list")
			return Command_type::list;

		throw std::runtime_error{ "unknown command\n" };
	}
	std::ostream& operator<<(std::ostream& os, Command_type& type)
	{
		if (type == string_to_command("add"))
			return os << '(' << "add" << ')';
		if (type == string_to_command("update"))
			return os << '(' << "update" << ')';
		if (type == string_to_command("delete"))
			return os << '(' << "delete" << ')';
		if (type == string_to_command("mark_in_progress"))
			return os << '(' << "mark_in_progress" << ')';
		if (type == string_to_command("mark_done"))
			return os << '(' << "mark_done" << ')';
		if (type == string_to_command("list"))
			return os << '(' << "list" << ')';

		return os << '(' << "unkown command" << ')';
	}
	std::ostream& operator<<(std::ostream& os, Command& command)
	{
		return os << '(' << command.command_type << '(' << command.argument << ')' << ')';
	}
}