#include "Headers/Division.h"

Division::Division(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Division::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left);
    auto right = DeepCopy(exp->right);
    auto left_exp = ExpressionType(left);
    auto right_exp = ExpressionType(right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->left = std::make_shared<StringNode>("-");
    new_exp->left->left = std::make_shared<StringNode>("*");
    new_exp->left->right = std::make_shared<StringNode>("*");
    new_exp->right = std::make_shared<StringNode>("^");
    new_exp->right->left = exp->right;
    new_exp->right->right = std::make_shared<IntNode>(2);
    new_exp->left->left->right = exp->right;
    new_exp->left->right->left = exp->left;
    new_exp->left->left->left = left;
    new_exp->left->right->right = right;
    exp = new_exp;
}
