#include "Node.h"

Node::Node(void* data_) : data(data_), left(nullptr), right(nullptr) {}

std::ostream &operator<<(std::ostream &os, const Node &node_) {
    node_.printNode(os);
    return os;
}
