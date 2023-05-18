#include "Headers/Logarithm.h"

Logarithm::Logarithm(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Logarithm::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right.lock());
    auto arg_exp = ExpressionType(arg);
    arg = arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->right = exp->right;
    new_exp->left = std::weak_ptr<Node>(arg);
    return new_exp;
}
