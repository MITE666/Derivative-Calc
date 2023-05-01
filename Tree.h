#ifndef OOP_TREE_H
#define OOP_TREE_H

#include "IntNode.h"
#include "FloatNode.h"
#include "StringNode.h"
#include <queue>
#include <stack>
#include <sstream>
#include <memory>
#include <map>

class Tree {
private:
    std::string expression;
    std::queue<std::shared_ptr<Node>> queue;
    std::shared_ptr<Node> root;
    std::map<std::string, int> priority = {
            std::make_pair("+", 0), std::make_pair("-", 0),
            std::make_pair("*", 1), std::make_pair("/", 1),
            std::make_pair("^", 2), std::make_pair("sin", 3),
            std::make_pair("cos", 3), std::make_pair("tan", 3),
            std::make_pair("cot", 3), std::make_pair("arcsin", 3),
            std::make_pair("arccos", 3), std::make_pair("arctan", 3),
            std::make_pair("arccot", 3), std::make_pair("ln", 3)
    };
    [[nodiscard]] static bool isInt(const std::string& elem) ;
    [[nodiscard]] static bool isFloat(const std::string& elem);

public:
    explicit Tree(std::string &expression_);
    void Convert(std::queue<std::shared_ptr<Node>> queue_);
    void PrintQueue();
};


#endif //OOP_TREE_H
