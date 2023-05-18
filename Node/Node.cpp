#include "Headers/Node.h"

Node::Node(void* data_) : data(data_), left(), right() {}

std::ostream &operator<<(std::ostream &os, const Node &node_) {
    if(!node_.left.expired())
        os << "( " << *node_.left.lock();
    node_.printNode(os);
    if(node_.left.expired() && !node_.right.expired())
        os << "( ";
    if(!node_.right.expired())
        os << *node_.right.lock() << ") ";
    return os;
}
