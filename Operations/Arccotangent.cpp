#include "Headers/Arccotangent.h"

Arccotangent::Arccotangent(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Arccotangent::Differentiate(std::string &var) {
    auto arg = exp->get_right()->clone();
    auto arg_exp = ExpressionType(exp->get_right());
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("-");
    new_exp->set_left(std::make_shared<Node<int>>(0));
    new_exp->set_right(std::make_shared<Node<std::string>>("/"));
    new_exp->get_right()->set_left(exp->get_right());
    new_exp->get_right()->set_right(std::make_shared<Node<std::string>>("+"));
    new_exp->get_right()->get_right()->set_left(std::make_shared<Node<std::string>>("^"));
    new_exp->get_right()->get_right()->set_right(std::make_shared<Node<int>>(1));
    new_exp->get_right()->get_right()->get_left()->set_left(arg);
    new_exp->get_right()->get_right()->get_left()->set_right(std::make_shared<Node<int>>(2));
    exp = new_exp;
}