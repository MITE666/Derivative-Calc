#include "Headers/Arcsinus.h"

Arcsinus::Arcsinus(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Arcsinus::Differentiate(std::string &var) {
    auto arg = DeepCopy(exp->right.lock());
    auto arg_exp = ExpressionType(arg);
    arg = arg_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("/");
    new_exp->left = std::weak_ptr<Node>(arg);
    new_exp->right = std::weak_ptr<Node>(std::make_shared<StringNode>("^"));
    new_exp->right.lock()->left = std::weak_ptr<Node>(std::make_shared<StringNode>("-"));
    new_exp->right.lock()->right = std::weak_ptr<Node>(std::make_shared<FloatNode>(0.5));
    new_exp->right.lock()->left.lock()->left = std::weak_ptr<Node>(std::make_shared<IntNode>(1));
    new_exp->right.lock()->left.lock()->right = std::weak_ptr<Node>(std::make_shared<StringNode>("^"));
    new_exp->right.lock()->left.lock()->right.lock()->left = exp->right;
    new_exp->right.lock()->left.lock()->right.lock()->right = std::weak_ptr<Node>(std::make_shared<IntNode>(2));
    return new_exp;
}
