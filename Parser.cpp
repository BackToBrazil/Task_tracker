#include "Parser.h"
namespace task_tracker {
    Command Parser::get_command(const std::vector<Token>& token_list)
    {
        // get the token and verify if its command is valid
        Token current_token = token_list[0];
        Command_type type;

        if (current_token.m_kind == Token_kind::COMMAND) {
            type = string_to_command(current_token.m_value);
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
        }
        else {
            return Command{ Command_type::unknown, "invalid" };
        }
    }
}