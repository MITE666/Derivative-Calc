#include "Headers/Node.h"

template <typename T>
Node<T>::Node(const T& data_) : data(data_) {}

template<typename T>
std::shared_ptr<BaseNode> Node<T>::clone() const {
    return std::make_shared<Node<T>>(*this);
}

template<typename T>
void Node<T>::PrintNode(std::ostream &os) const {
    os << data << " ";
}
