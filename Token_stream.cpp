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
    std::vector<std::string> Token_stream::separate_line(const std::string& line)
    {
        // add "teste1"
        // list in-progress
        // delete 1
        std::vector<std::string> words_list;
        std::string word;
        int quotation_mark_counter = 0;
        for (auto x : line) {
            if (x == '"') {
                quotation_mark_counter++;
            }
            if (quotation_mark_counter < 1) {
                if (!isspace(x)) {
                    word += x;
                }
                else {
                    words_list.push_back(word);
                    word.erase();
                }
            }
            if (quotation_mark_counter > 0) {
                if(quotation_mark_counter == 2){
                    words_list.push_back(word);
                    word.erase();
                }
                word += x;
            }
        }
        return words_list;
    }
    std::vector<Token> Token_stream::get_tokens(const std::string& line)
    {
        // read each word and translate it into Tokens
        std::vector<std::string> words_list = separate_line(line);  // separate the line into different words and creates a vector with each word
        std::vector<Token> token_list;
        std::string token;
        for (auto x : words_list) {
            if (isalpha(x.front())) {
                bool is_status = false;
                // verify if its not a Task_status
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
                std::string new_token;
                for (auto ch : x) {
                    if (ch != '"')
                        new_token += ch;
                }
                token_list.push_back(Token{ Token_kind::TASK_DESCRIPTION, new_token });
            }
        }
        return token_list;
    }
}