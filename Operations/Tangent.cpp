#include "Headers/Tangent.h"

Tangent::Tangent(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Tangent::Differentiate(std::string &var) {
    auto arg = exp->get_right()->clone();
    auto arg_exp = ExpressionType(exp->get_right());
    arg_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->set_left(exp->get_right());
    new_exp->set_right(std::make_shared<Node<std::string>>("^"));
    new_exp->get_right()->set_left(std::make_shared<Node<std::string>>("cos"));
    new_exp->get_right()->set_right(std::make_shared<Node<int>>(2));
    new_exp->get_right()->get_left()->set_right(arg);
    exp = new_exp;
}

void Tangent::Simplify() {
    if (exp->get_right() != nullptr) {
        auto expression = ExpressionType(exp->get_right());
        expression->Simplify();
    }
    auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(exp->get_right());
    if(string_ptr_arg)
        if(string_ptr_arg->get_data() == "arctan")
            exp = exp->get_right()->get_right();
}
