#include "Headers/Sinus.h"

Sinus::Sinus(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Sinus::Differentiate(std::string &var) {
    auto arg = exp->get_right()->clone();
    auto arg_exp = ExpressionType(exp->get_right());
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("*");
    new_exp->set_left(exp->get_right());
    new_exp->set_right(std::make_shared<Node<std::string>>("cos"));
    new_exp->get_right()->set_right(arg);
    exp = new_exp;
}