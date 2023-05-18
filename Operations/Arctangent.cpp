#include "Headers/Arctangent.h"

Arctangent::Arctangent(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Arctangent::Differentiate(std::string &var) {
    auto arg = exp->right->clone();
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->left = exp->right;
    new_exp->right = std::make_shared<Node<std::string>>("+");
    new_exp->right->left = std::make_shared<Node<std::string>>("^");
    new_exp->right->right = std::make_shared<Node<int>>(1);
    new_exp->right->left->left = arg;
    new_exp->right->left->right = std::make_shared<Node<int>>(2);
    exp = new_exp;
}