#include "Headers/Power.h"

Power::Power(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Power::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left);
    auto right = DeepCopy(exp->right);
    auto left_exp = ExpressionType(left);
    auto right_exp = ExpressionType(right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("+");
    new_exp->left = std::make_shared<StringNode>("*");
    new_exp->left->left = std::make_shared<StringNode>("*");
    new_exp->left->right = std::make_shared<StringNode>("^");
    new_exp->left->left->left = exp->right;
    new_exp->left->left->right = left;
    new_exp->left->right->left = exp->left;
    new_exp->left->right->right = std::make_shared<StringNode>("-");
    new_exp->left->right->right->left = exp->right;
    new_exp->left->right->right->right = std::make_shared<IntNode>(1);
    new_exp->right = std::make_shared<StringNode>("*");
    new_exp->right->left = std::make_shared<StringNode>("^");
    new_exp->right->right = std::make_shared<StringNode>("*");
    new_exp->right->left->left = exp->left;
    new_exp->right->left->right = exp->right;
    new_exp->right->right->left = std::make_shared<StringNode>("ln");
    new_exp->right->right->right = right;
    new_exp->right->right->left->right = exp->left;
    exp = new_exp;
}
