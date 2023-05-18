#include "Headers/Power.h"

Power::Power(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Power::Differentiate(std::string &var) {
    auto left = exp->left->clone();
    auto right = exp->right->clone();
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("+");
    new_exp->left = std::make_shared<Node<std::string>>("*");
    new_exp->left->left = std::make_shared<Node<std::string>>("*");
    new_exp->left->right = std::make_shared<Node<std::string>>("^");
    new_exp->left->left->left = right;
    new_exp->left->left->right = exp->left;
    new_exp->left->right->left = left;
    new_exp->left->right->right = std::make_shared<Node<std::string>>("-");
    new_exp->left->right->right->left = right;
    new_exp->left->right->right->right = std::make_shared<Node<int>>(1);
    new_exp->right = std::make_shared<Node<std::string>>("*");
    new_exp->right->left = std::make_shared<Node<std::string>>("^");
    new_exp->right->right = std::make_shared<Node<std::string>>("*");
    new_exp->right->left->left = left;
    new_exp->right->left->right = right;
    new_exp->right->right->left = std::make_shared<Node<std::string>>("ln");
    new_exp->right->right->right = exp->right;
    new_exp->right->right->left->right = left;
    exp = new_exp;
}