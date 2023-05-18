#include "Headers/Variable.h"

Variable::Variable(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Variable::Differentiate(std::string &var) {
    if(*(std::string*)exp->data == var)
        return std::make_shared<IntNode>(1);
    else
        return std::make_shared<IntNode>(0);
}
