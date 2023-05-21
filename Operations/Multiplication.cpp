#include "Headers/Multiplication.h"

Multiplication::Multiplication(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Multiplication::Differentiate(std::string &var) {
    auto left = exp->get_left()->clone();
    auto right = exp->get_right()->clone();
    auto left_exp = ExpressionType(exp->get_left());
    auto right_exp = ExpressionType(exp->get_right());
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("+");
    new_exp->set_left(std::make_shared<Node<std::string>>("*"));
    new_exp->set_right(std::make_shared<Node<std::string>>("*"));
    new_exp->get_right()->set_left(left);
    new_exp->get_left()->set_right(right);
    new_exp->get_right()->set_right(exp->get_right());
    new_exp->get_left()->set_left(exp->get_left());
    exp = new_exp;
}