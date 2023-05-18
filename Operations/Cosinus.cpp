#include "Headers/Cosinus.h"

Cosinus::Cosinus(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

void Cosinus::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right);
    auto arg_exp = ExpressionType(exp->right);
    arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("-");
    new_exp->left = std::make_shared<IntNode>(0);
    new_exp->right = std::make_shared<StringNode>("*");
    new_exp->right->left = exp->right;
    new_exp->right->right = std::make_shared<StringNode>("sin");
    new_exp->right->right->right = arg;
    exp = new_exp;
}