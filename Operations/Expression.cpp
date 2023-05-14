#include "Expression.h"

Expression::Expression(std::shared_ptr<Node>& exp_) : exp(exp_) {}

std::shared_ptr<Node> Expression::DeepCopy(std::shared_ptr<Node> node) {
    auto newNode = node;
    if(node->right != nullptr)
        newNode->right = DeepCopy(node->right);
    if(node->left != nullptr)
        newNode->left = DeepCopy(node->left);
    return newNode;
}
