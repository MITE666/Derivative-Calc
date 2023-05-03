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
            std::make_pair("+\0", 0), std::make_pair("-\0", 0),
            std::make_pair("*\0", 1), std::make_pair("/\0", 1),
            std::make_pair("^\0", 2), std::make_pair("sin\0", 3),
            std::make_pair("cos\0", 3), std::make_pair("tan\0", 3),
            std::make_pair("cot\0", 3), std::make_pair("arcsin\0", 3),
            std::make_pair("arccos\0", 3), std::make_pair("arctan\0", 3),
            std::make_pair("arccot\0", 3), std::make_pair("ln\0", 3)
    };
    std::vector<std::string> binaryOp = {
            "+\0", "-\0", "/\0", "*\0", "^\0"
    };
    std::vector<std::string> unaryOp = {
            "sin\0", "cos\0", "tan\0", "cot\0", "arcsin\0", "arccos\0", "arctan\0", "arccot\0", "ln\0"
    };
    [[nodiscard]] static bool isInt(const std::string& elem) ;
    [[nodiscard]] static bool isFloat(const std::string& elem);

public:
    explicit Tree(std::string &expression_);
    void Convert(std::queue<std::shared_ptr<Node>> queue_);
    void PrintQueue();
    void PrintTree();
};


#endif //OOP_TREE_H
