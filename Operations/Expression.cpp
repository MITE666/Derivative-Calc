#include "Expression.h"

Expression::Expression(std::shared_ptr<Node>& exp_) : exp(exp_) {}

std::shared_ptr<Node> Expression::DeepCopy(std::shared_ptr<Node> node) {
    if(node == nullptr)
        return nullptr;
    auto newNode = node->clone();
    newNode->right = DeepCopy(node->right);
    newNode->left = DeepCopy(node->left);
    return newNode;
}
