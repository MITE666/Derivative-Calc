#include "Headers/Addition.h"

Addition::Addition(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Addition::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left);
    auto right = DeepCopy(exp->right);
    auto left_exp = ExpressionType(left);
    auto right_exp = ExpressionType(right);
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("+");
    new_exp->left = left;
    new_exp->right = right;
    exp = new_exp;
}
