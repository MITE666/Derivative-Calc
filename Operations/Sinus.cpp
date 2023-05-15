#include "Headers/Sinus.h"

Sinus::Sinus(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Sinus::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("*");
    new_exp->left = exp->right;
    new_exp->right = std::make_shared<StringNode>("cos");
    new_exp->right->right = arg;
    exp = new_exp;
}
