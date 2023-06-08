#include "Headers/Constant.h"

Constant::Constant(std::shared_ptr<BaseNode>& exp_) : Expression(exp_) {}

void Constant::Differentiate(std::string &var) {
    if(var == "how else should i use it? ))")
        return;
    exp = std::make_shared<Node<int>>(0);
}

void Constant::Simplify() { }
