#include "Headers/Arccotangent.h"

Arccotangent::Arccotangent(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Arccotangent::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("-");
    new_exp->left = std::make_shared<IntNode>(0);
    new_exp->right = std::make_shared<StringNode>("/");
    new_exp->right->left = exp->right;
    new_exp->right->right = std::make_shared<StringNode>("+");
    new_exp->right->right->left = std::make_shared<StringNode>("^");
    new_exp->right->right->right = std::make_shared<IntNode>(1);
    new_exp->right->right->left->left = arg;
    new_exp->right->right->left->right = std::make_shared<IntNode>(2);
    exp = new_exp;
}
