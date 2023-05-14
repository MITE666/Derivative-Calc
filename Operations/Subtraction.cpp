#include "Subtraction.h"

Subtraction::Subtraction(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Subtraction::Differentiate(std::string &var) {
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
}