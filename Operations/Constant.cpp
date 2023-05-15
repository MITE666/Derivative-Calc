#include "Headers/Constant.h"

Constant::Constant(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Constant::Differentiate(std::string &var) {
    if(var == "how else should i use it?")
        return;
    exp = std::make_shared<IntNode>(0);
}
