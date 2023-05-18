#include "Headers/Tangent.h"

Tangent::Tangent(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Tangent::Differentiate(std::string &var) {
    auto arg = exp->right->clone();
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->left = exp->right;
    new_exp->right = std::make_shared<StringNode>("^");
    new_exp->right->left = std::make_shared<StringNode>("cos");
    new_exp->right->right = std::make_shared<IntNode>(2);
    new_exp->right->left->right = arg;
    exp = new_exp;
}