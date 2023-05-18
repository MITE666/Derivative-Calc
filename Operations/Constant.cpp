#include "Headers/Constant.h"

Constant::Constant(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Constant::Differentiate(std::string &var) {
    if(var == "how else should i use it?")
        return nullptr;
    return std::make_shared<IntNode>(0);
}
