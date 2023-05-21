#include "Headers/Cotangent.h"

Cotangent::Cotangent(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Cotangent::Differentiate(std::string &var) {
    auto arg = exp->get_right()->clone();
    auto arg_exp = ExpressionType(exp->get_right());
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("-");
    new_exp->set_left(std::make_shared<Node<int>>(0));
    new_exp->set_right(std::make_shared<Node<std::string>>("/"));
    new_exp->get_right()->set_left(exp->get_right());
    new_exp->get_right()->set_right(std::make_shared<Node<std::string>>("^"));
    new_exp->get_right()->get_right()->set_left(std::make_shared<Node<std::string>>("sin"));
    new_exp->get_right()->get_right()->set_right(std::make_shared<Node<int>>(2));
    new_exp->get_right()->get_right()->get_left()->set_right(arg);
    exp = new_exp;
}