#include "Headers/Division.h"

Division::Division(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Division::Differentiate(std::string &var) {
    auto left = exp->get_left()->clone();
    auto right = exp->get_right()->clone();
    auto left_exp = ExpressionType(exp->get_left());
    auto right_exp = ExpressionType(exp->get_right());
    left_exp->Differentiate(var);
    right_exp->Differentiate(var);
    std::shared_ptr<BaseNode> new_exp = std::make_shared<Node<std::string>>("/");
    new_exp->set_left(std::make_shared<Node<std::string>>("-"));
    new_exp->get_left()->set_left(std::make_shared<Node<std::string>>("*"));
    new_exp->get_left()->set_right(std::make_shared<Node<std::string>>("*"));
    new_exp->set_right(std::make_shared<Node<std::string>>("^"));
    new_exp->get_right()->set_left(right);
    new_exp->get_right()->set_right(std::make_shared<Node<int>>(2));
    new_exp->get_left()->get_left()->set_right(right);
    new_exp->get_left()->get_right()->set_left(left);
    new_exp->get_left()->get_left()->set_left(exp->get_left());
    new_exp->get_left()->get_right()->set_right(exp->get_right());
    exp = new_exp;
}

void Division::Simplify() {
    if (exp->get_left() != nullptr) {
        auto expression = ExpressionType(exp->get_left());
        expression->Simplify();
    }
    if (exp->get_right() != nullptr) {
        auto expression = ExpressionType(exp->get_right());
        expression->Simplify();
    }
    auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(exp->get_left());
    auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(exp->get_right());
    auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(exp->get_left());
    auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(exp->get_right());
    if(int_ptr_right && int_ptr_left) {
        exp = std::make_shared<Node<float>>((float)(int_ptr_left->get_data() / int_ptr_right->get_data()));
        return;
    }
    if(float_ptr_right && float_ptr_left) {
        exp = std::make_shared<Node<float>>((float)(float_ptr_left->get_data() * float_ptr_right->get_data()));
        return;
    }
    if(int_ptr_right) {
        if(int_ptr_right->get_data() == 1) {
            exp = exp->get_left();
            return;
        }
    }
    if(int_ptr_left) {
        if(int_ptr_left->get_data() == 0) {
            exp = std::make_shared<Node<int>>(0);
            return;
        }
    }
}
