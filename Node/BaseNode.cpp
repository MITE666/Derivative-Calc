#include "Headers/BaseNode.h"

std::ostream &operator<<(std::ostream &os, const BaseNode &baseNode_) {
    if(baseNode_.left != nullptr)
        os << "( " << *baseNode_.left;
    baseNode_.PrintNode(os);
    if(baseNode_.left == nullptr && baseNode_.right != nullptr)
        os << "( ";
    if(baseNode_.right != nullptr)
        os << *baseNode_.right << ") ";
    return os;
}

BaseNode::BaseNode() : left(nullptr), right(nullptr) {}
