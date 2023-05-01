#include "IntNode.h"

IntNode::IntNode(int data_) : Node(&data_) {}

void IntNode::printNode(std::ostream &os) const {
    os << *(int*)data << " ";
}

std::shared_ptr<Node> IntNode::clone() const {
    return std::make_shared<IntNode>(*this);
}