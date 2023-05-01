#include "StringNode.h"

StringNode::StringNode(const std::string &data_) : Node(new std::string(data_ + "\0")){}

void StringNode::printNode(std::ostream &os) const {
    os << *(std::string*)data << " ";
}

std::shared_ptr<Node> StringNode::clone() const {
    return std::make_shared<StringNode>(*this);
}

StringNode::~StringNode() {
    delete static_cast<std::string*>(data);
}
