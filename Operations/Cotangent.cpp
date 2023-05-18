#include "Headers/Cotangent.h"

Cotangent::Cotangent(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Cotangent::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right.lock());
    auto arg_exp = ExpressionType(arg);
    arg = arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("-");
    new_exp->left = std::weak_ptr<Node>(std::make_shared<IntNode>(0));
    new_exp->right = std::weak_ptr<Node>(std::make_shared<StringNode>("/"));
    new_exp->right.lock()->left = std::weak_ptr<Node>(arg);
    new_exp->right.lock()->right = std::weak_ptr<Node>(std::make_shared<StringNode>("^"));
    new_exp->right.lock()->right.lock()->left = std::weak_ptr<Node>(std::make_shared<StringNode>("sin"));
    new_exp->right.lock()->right.lock()->right = std::weak_ptr<Node>(std::make_shared<IntNode>(2));
    new_exp->right.lock()->right.lock()->left.lock()->right = exp->right;
    return new_exp;
}
