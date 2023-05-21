#include "Headers/Logarithm.h"

Logarithm::Logarithm(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Logarithm::Differentiate(std::string &var) {
    auto arg = exp->get_right()->clone();
    auto arg_exp = ExpressionType(exp->get_right());
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->set_right(arg);
    new_exp->set_left(exp->get_right());
    exp = new_exp;
}