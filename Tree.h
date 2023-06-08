#ifndef OOP_TREE_H
#define OOP_TREE_H

#include "Node/Headers/Node.h"
#include "EmptyStackException.h"
#include <queue>
#include <stack>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>

class Tree {
private:
    std::string expression;
    std::queue<std::shared_ptr<BaseNode>> queue;
    std::map<std::string, int> priority = {
            std::make_pair("+", 0), std::make_pair("-", 0),
            std::make_pair("*", 1), std::make_pair("/", 1),
            std::make_pair("^", 2), std::make_pair("sin", 3),
            std::make_pair("cos", 3), std::make_pair("tan", 3),
            std::make_pair("cot", 3), std::make_pair("arcsin", 3),
            std::make_pair("arccos", 3), std::make_pair("arctan", 3),
            std::make_pair("arccot", 3), std::make_pair("ln", 3)
    };
    std::vector<std::string> binaryOp = {
            "+", "-", "/", "*", "^"
    };
    std::vector<std::string> unaryOp = {
            "sin", "cos", "tan", "cot", "arcsin", "arccos", "arctan", "arccot", "ln"
    };
    [[nodiscard]] static bool isInt(const std::string& elem) ;
    [[nodiscard]] static bool isFloat(const std::string& elem);

public:
    std::shared_ptr<BaseNode> root;
    explicit Tree(std::string &expression_);
    void Convert();
    friend std::ostream &operator<<(std::ostream &os, const Tree &tree_);
};


#endif //OOP_TREE_H