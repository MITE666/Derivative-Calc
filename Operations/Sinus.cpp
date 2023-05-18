#include "Headers/Sinus.h"

Sinus::Sinus(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Sinus::Differentiate(std::string &var) {
    auto arg = exp->right->clone();
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("*");
    new_exp->left = exp->right;
    new_exp->right = std::make_shared<Node<std::string>>("cos");
    new_exp->right->right = arg;
    exp = new_exp;
}