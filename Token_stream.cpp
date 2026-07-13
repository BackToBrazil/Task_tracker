#include "Token_stream.h"
namespace task_tracker {
    std::string task_tracker::to_string(const Token_kind& tk) {
        switch (tk)
        {
        case Token_kind::COMMAND:
            return "COMMAND";
        case Token_kind::TASK_ID:
            return "TASK_ID";
        case Token_kind::TASK_DESCRIPTION:
            return "TASK_DESCRIPTION";
        case Token_kind::TASK_STATUS:
            return "TASK_STATUS";
        case Token_kind::END_OF_FILE:
            return "END_OF_FILE";
        case Token_kind::QUIT:
            return "QUIT";
        default:
            return "UNKNOWN";
        }
    }
    std::ostream& operator<<(std::ostream& os, const Token_kind& token_kind) {
        return os << to_string(token_kind);
    }
    std::ostream& operator<<(std::ostream& os, const task_tracker::Token& token) {
        return os << '(' << token.m_kind << ')' << '(' << token.m_value << ')';
    }
    std::vector<Token> Token_stream::get_tokens(const std::string& line)
    {
        std::vector<Token> token_list;
        std::vector<std::string> words_list;
        std::string token;
        // separate the line into different words
        for (auto x: line) {
            if (!isspace(x)) {
                token += x;
                //std::cout << "char added: " << x << '\n';
            }
            else {
                words_list.push_back(token);
                //std::cout << "token added: " << token << '\n';
                token.erase();
            }
        }
        // gambiarra
        words_list.push_back(token);
        //std::cout << "token added: " << token << '\n';
        token.erase();
        // read each word and translate them into Tokens
        for (auto x : words_list) {
            if (isalpha(x.front())) {
                bool is_status = false;
                // verify if its not a token_status first
                for (auto y : all_Task_status) {
                    if (x == y) {
                        token_list.push_back(Token{ Token_kind::TASK_STATUS, x });
                        is_status = true;
                        break;
                    }
                }
                if (!is_status)
                    token_list.push_back(Token{ Token_kind::COMMAND, x });
            }
            if (isdigit(x.front())) {
                token_list.push_back(Token{ Token_kind::TASK_ID, x });
            }
            if (x.front() == '"') {
                // remove the '"' from the value first
                token_list.push_back(Token{ Token_kind::TASK_DESCRIPTION, x });
            }
        }
        return token_list;
    }
}