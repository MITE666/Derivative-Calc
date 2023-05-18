#include "Headers/Logarithm.h"

Logarithm::Logarithm(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Logarithm::Differentiate(std::string &var) {
    auto arg = exp->right->clone();
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->right = arg;
    new_exp->left = exp->right;
    exp = new_exp;
}