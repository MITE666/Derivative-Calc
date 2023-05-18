#include "Headers/Power.h"

Power::Power(std::shared_ptr<Node>& exp_) : Expression(exp_) {}

std::shared_ptr<Node> Power::Differentiate(std::string &var) {
    auto left = DeepCopy(exp->left.lock());
    auto right = DeepCopy(exp->right.lock());
    auto left_exp = ExpressionType(left);
    auto right_exp = ExpressionType(right);
    left = left_exp->Differentiate(var);
    right = right_exp->Differentiate(var);
    std::shared_ptr<Node> new_exp = std::make_shared<StringNode>("+");
    new_exp->left = std::weak_ptr<Node>(std::make_shared<StringNode>("*"));
    new_exp->left.lock()->left = std::weak_ptr<Node>(std::make_shared<StringNode>("*"));
    new_exp->left.lock()->right = std::weak_ptr<Node>(std::make_shared<StringNode>("^"));
    new_exp->left.lock()->left.lock()->left = exp->right;
    new_exp->left.lock()->left.lock()->right = std::weak_ptr<Node>(left);
    new_exp->left.lock()->right.lock()->left = exp->left;
    new_exp->left.lock()->right.lock()->right = std::weak_ptr<Node>(std::make_shared<StringNode>("-"));
    new_exp->left.lock()->right.lock()->right.lock()->left = exp->right;
    new_exp->left.lock()->right.lock()->right.lock()->right = std::weak_ptr<Node>(std::make_shared<IntNode>(1));
    new_exp->right = std::weak_ptr<Node>(std::make_shared<StringNode>("*"));
    new_exp->right.lock()->left = std::weak_ptr<Node>(std::make_shared<StringNode>("^"));
    new_exp->right.lock()->right = std::weak_ptr<Node>(std::make_shared<StringNode>("*"));
    new_exp->right.lock()->left.lock()->left = exp->left;
    new_exp->right.lock()->left.lock()->right = exp->right;
    new_exp->right.lock()->right.lock()->left = std::weak_ptr<Node>(std::make_shared<StringNode>("ln"));
    new_exp->right.lock()->right.lock()->right = std::weak_ptr<Node>(right);
    new_exp->right.lock()->right.lock()->left.lock()->right = exp->left;
    return new_exp;
}
