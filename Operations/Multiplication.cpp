#include "Headers/Multiplication.h"

Multiplication::Multiplication(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Multiplication::Differentiate(std::string &var) {
    auto left = exp->left->clone();
    auto right = exp->right->clone();
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("+");
    new_exp->left = std::make_shared<StringNode>("*");
    new_exp->right = std::make_shared<StringNode>("*");
    new_exp->right->left = left;
    new_exp->left->right = right;
    new_exp->right->right = exp->right;
    new_exp->left->left = exp->left;
    exp = new_exp;
}