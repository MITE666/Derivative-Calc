#include "Headers/Power.h"

Power::Power(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Power::Differentiate(std::string &var) {
    auto left = exp->get_left()->clone();
    auto right = exp->get_right()->clone();
    auto left_exp = ExpressionType(exp->get_left());
    auto right_exp = ExpressionType(exp->get_right());
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("+");
    new_exp->set_left(std::make_shared<Node<std::string>>("*"));
    new_exp->get_left()->set_left(std::make_shared<Node<std::string>>("*"));
    new_exp->get_left()->set_right(std::make_shared<Node<std::string>>("^"));
    new_exp->get_left()->get_left()->set_left(right);
    new_exp->get_left()->get_left()->set_right(exp->get_left());
    new_exp->get_left()->get_right()->set_left(left);
    new_exp->get_left()->get_right()->set_right(std::make_shared<Node<std::string>>("-"));
    new_exp->get_left()->get_right()->get_right()->set_left(right);
    new_exp->get_left()->get_right()->get_right()->set_right(std::make_shared<Node<int>>(1));
    new_exp->set_right(std::make_shared<Node<std::string>>("*"));
    new_exp->get_right()->set_left(std::make_shared<Node<std::string>>("^"));
    new_exp->get_right()->set_right(std::make_shared<Node<std::string>>("*"));
    new_exp->get_right()->get_left()->set_left(left);
    new_exp->get_right()->get_left()->set_right(right);
    new_exp->get_right()->get_right()->set_left(std::make_shared<Node<std::string>>("ln"));
    new_exp->get_right()->get_right()->set_right(exp->get_right());
    new_exp->get_right()->get_right()->get_left()->set_right(left);
    exp = new_exp;
}