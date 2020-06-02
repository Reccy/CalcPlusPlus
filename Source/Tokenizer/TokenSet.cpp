#include "TokenSet.h"

TokenSet::TokenSet(std::queue<Token*> tokens) {
    while (!tokens.empty()) {
        this->tokens.push_back(tokens.front());
        tokens.pop();
    }
}

TokenSet::TokenSet(std::vector<Token*> tokens) {
	this->tokens = tokens;
};

bool TokenSet::is_valid() {
    if (std::any_of(this->tokens.begin(), this->tokens.end(), [](Token* t) { return !t->is_valid(); })) {
        return false;
    };
    return true;
};

std::string TokenSet::str() {
    std::stringstream ss;

    for (Token* const& token : this->tokens) {
        ss << token->to_string() << "\n";
    }

    return ss.str();
};

std::vector<Token*>::iterator TokenSet::begin() {
    return this->tokens.begin();
};

std::vector<Token*>::iterator TokenSet::end() {
    return this->tokens.end();
};
