#include "Node.h"

Node::Node(void* data_) : data(data_), left(nullptr), right(nullptr) {}

std::ostream &operator<<(std::ostream &os, const Node &node_) {
    if(node_.left != nullptr)
        os << *node_.left;
    if(node_.right != nullptr)
        os << *node_.right;
    node_.printNode(os);
    return os;
}
