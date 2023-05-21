#include "Headers/Subtraction.h"

Subtraction::Subtraction(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Subtraction::Differentiate(std::string &var) {
    auto left_exp = ExpressionType(exp->get_left());
    auto right_exp = ExpressionType(exp->get_right());
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
}