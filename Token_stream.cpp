#include "Token_stream.h"
#include <iostream>
namespace task_tracker {
    std::vector<Token>& Token_stream::get_tokens(const std::string& line)
    {
        for (auto x : line) {
            std::cout << x;
        }


        std::vector<Token> token_list{};
        return token_list;
    }
}