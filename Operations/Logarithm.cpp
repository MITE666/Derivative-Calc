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

void Logarithm::Simplify() {
    if (exp->get_right() != nullptr) {
        auto expression = ExpressionType(exp->get_right());
        expression->Simplify();
    }
    auto int_ptr = std::dynamic_pointer_cast<Node<int>>(exp->get_right());
    auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(exp->get_right());
    if(int_ptr) {
        if(int_ptr->get_data() == 1)
            exp = std::make_shared<Node<int>>(0);
    } else if(string_ptr_arg) {
        if(string_ptr_arg->get_data() == "e")
            exp = std::make_shared<Node<int>>(1);
    }
}
