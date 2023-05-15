#include "Headers/Logarithm.h"

Logarithm::Logarithm(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Logarithm::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->right = arg;
    new_exp->left = exp->right;
    exp = new_exp;
}
