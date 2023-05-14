#include "Division.h"

Division::Division(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Division::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left);
    auto right = DeepCopy(exp->right);
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->left = std::make_shared<StringNode>("-");
    new_exp->left->left = std::make_shared<StringNode>("*");
    new_exp->left->right = std::make_shared<StringNode>("*");
    new_exp->right = std::make_shared<StringNode>("*");
    new_exp->right->left = right;
    new_exp->right->right = right;
    new_exp->left->left->right = right;
    new_exp->left->right->left = left;
    new_exp->left->left->left = exp->left;
    new_exp->left->right->right = exp->right;
    exp = new_exp;
}
