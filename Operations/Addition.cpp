#include "Headers/Addition.h"

Addition::Addition(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Addition::Differentiate(std::string &var) {
    auto left_exp = ExpressionType(exp->left);
    auto right_exp = ExpressionType(exp->right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
}