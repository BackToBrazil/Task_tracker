#include "Parser.h"
namespace task_tracker {
    Command_type task_tracker::string_to_command(const std::string& type) {
        if (type == "add")
            return Command_type::add;
        if (type == "delete")
            return Command_type::delete_;
        if (type == "update")
            return Command_type::update;
        if (type == "mark-in-progress")
            return Command_type::mark_in_progress;
        if (type == "mark-done")
            return Command_type::mark_done;
        if (type == "list")
            return Command_type::list;
        return Command_type::unknown;
    }
    Command Parser::get_command(const std::vector<Token>& token_list)
    {
        // get the token and verify if its command is valid
        Token current_token = token_list[0];
        Command_type type;

        if (current_token.m_kind == Token_kind::COMMAND) {
            type = task_tracker::string_to_command(current_token.m_value);
            // verification to see if the command is a list command
            if (type == Command_type::list && token_list.size() <= 1) {
                return Command{ type, "all"};
            }
            else {
                current_token = token_list[1];
            }
            if (current_token.m_kind == Token_kind::TASK_DESCRIPTION) {
                return Command{ type, current_token.m_value };
            }
            if (current_token.m_kind == Token_kind::TASK_ID) {
                return Command{ type, current_token.m_value };
            }
            if (current_token.m_kind == Token_kind::TASK_STATUS) {
                return Command{ type, current_token.m_value };
            }
            else {
                return Command{ Command_type::unknown, "invalid command" };
            }
        }
        return Command{ Command_type::unknown, "invalid command" };
    }
}