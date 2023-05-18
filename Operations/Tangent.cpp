#include "Headers/Tangent.h"

Tangent::Tangent(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Tangent::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(arg);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->left = arg;
    new_exp->right = std::make_shared<StringNode>("^");
    new_exp->right->left = std::make_shared<StringNode>("cos");
    new_exp->right->right = std::make_shared<IntNode>(2);
    new_exp->right->left->right = exp->right;
    exp = new_exp;
}
