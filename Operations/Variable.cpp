#include "Headers/Variable.h"

Variable::Variable(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Variable::Differentiate(std::string &var) {
    if(std::dynamic_pointer_cast<Node<std::string>>(exp)->get_data() == var)
        exp = std::make_shared<Node<int>>(1);
    else
        exp = std::make_shared<Node<int>>(0);
}

void Variable::Simplify() { }
