#include "Headers/Variable.h"

Variable::Variable(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Variable::Differentiate(std::string &var) {
    if(*(std::string*)exp->data == var)
        exp = std::make_shared<IntNode>(1);
    else
        exp = std::make_shared<IntNode>(0);
}