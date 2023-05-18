#include "Headers/BaseNode.h"

int BaseNode::nr_parentheses = 0;

std::ostream &operator<<(std::ostream &os, const BaseNode &baseNode_) {
    if(BaseNode::nr_parentheses == 0) {
        ++BaseNode::nr_parentheses;
        if(baseNode_.left != nullptr)
            os << *baseNode_.left;
        baseNode_.PrintNode(os);
        if(baseNode_.right != nullptr)
            os << *baseNode_.right;
    }
    else {
        if(baseNode_.left != nullptr)
            os << "( " << *baseNode_.left;
        baseNode_.PrintNode(os);
        if(baseNode_.left == nullptr && baseNode_.right != nullptr)
            os << "( ";
        if(baseNode_.right != nullptr)
            os << *baseNode_.right << ") ";
    }
    return os;
}

BaseNode::BaseNode() : left(nullptr), right(nullptr) {}
