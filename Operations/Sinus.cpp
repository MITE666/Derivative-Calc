#include "Headers/Sinus.h"

Sinus::Sinus(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Sinus::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right.lock());
    auto arg_exp = ExpressionType(arg);
    arg = arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("*");
    new_exp->left = std::weak_ptr<Node>(arg);
    new_exp->right = std::weak_ptr<Node>(std::make_shared<StringNode>("cos"));
    new_exp->right.lock()->right = exp->right;
    return new_exp;
}
