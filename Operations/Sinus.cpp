#include "Headers/Sinus.h"

Sinus::Sinus(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Sinus::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(arg);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("*");
    new_exp->left = arg;
    new_exp->right = std::make_shared<StringNode>("cos");
    new_exp->right->right = exp->right;
    exp = new_exp;
}
