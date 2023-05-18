#include "Headers/Division.h"

Division::Division(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Division::Differentiate(std::string &var) {
    auto left = exp->left->clone();
    auto right = exp->right->clone();
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->left = std::make_shared<Node<std::string>>("-");
    new_exp->left->left = std::make_shared<Node<std::string>>("*");
    new_exp->left->right = std::make_shared<Node<std::string>>("*");
    new_exp->right = std::make_shared<Node<std::string>>("^");
    new_exp->right->left = right;
    new_exp->right->right = std::make_shared<Node<int>>(2);
    new_exp->left->left->right = right;
    new_exp->left->right->left = left;
    new_exp->left->left->left = exp->left;
    new_exp->left->right->right = exp->right;
    exp = new_exp;
}