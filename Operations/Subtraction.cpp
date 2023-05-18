#include "Headers/Subtraction.h"

Subtraction::Subtraction(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Subtraction::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left.lock());
    auto right = DeepCopy(exp->right.lock());
    auto left_exp = ExpressionType(left);
    auto right_exp = ExpressionType(right);
    left = left_exp->Differentiate(var);
    right = right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("-");
    new_exp->left = std::weak_ptr<Node>(left);
    new_exp->right = std::weak_ptr<Node>(right);
    return new_exp;
}
