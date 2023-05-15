#include "Headers/Node.h"

Node::Node(void* data_) : data(data_), left(nullptr), right(nullptr) {}

std::ostream &operator<<(std::ostream &os, const Node &node_) {
    if(node_.left != nullptr)
        os << "( " << *node_.left;
    node_.printNode(os);
    if(node_.left == nullptr && node_.right != nullptr)
        os << "( ";
    if(node_.right != nullptr)
        os << *node_.right << ") ";
    return os;
}
