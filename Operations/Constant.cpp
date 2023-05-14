#include "Constant.h"

Constant::Constant(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Constant::Differentiate(std::string &var) {
    exp = std::make_shared<IntNode>(0);
}
