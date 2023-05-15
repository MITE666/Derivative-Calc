#include "Headers/FloatNode.h"

FloatNode::FloatNode(float data_) : Node(new float(data_)) {}

void FloatNode::printNode(std::ostream &os) const {
    os << *(float*)data << " ";
}

std::shared_ptr<Node> FloatNode::clone() const {
    return std::make_shared<FloatNode>(*this);
}
