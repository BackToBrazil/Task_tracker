#include "Parser.h"
namespace task_tracker {
    Command Parser::get_command(const std::vector<Token>& token_list)
    {
        const Token& first_token = token_list[0].m_kind;
        // get the token and verify if its command is valid
        if (first_token.m_kind == Token_kind::COMMAND) {
            if (first_token.m_value == "add") {
                
            }
        }
        else {
            throw std::runtime_error{ "invalid command\n" };
        }
        return Command{"asd"};
    }
}