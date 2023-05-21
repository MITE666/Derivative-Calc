#include "Headers/Node.h"

template <typename T>
Node<T>::Node(T data_) : data(data_) {} // cppcheck-suppress passedByValue

template <>
Node<int>::Node(int data_) : data(data_) {}

template <>
Node<float>::Node(float data_) : data(data_) {}

template <>
Node<std::string>::Node(std::string data_) : data(std::move(data_)) {}

template<typename T>
std::shared_ptr<BaseNode> Node<T>::clone() const {
    return std::make_shared<Node<T>>(*this);
}

template<typename T>
void Node<T>::PrintNode(std::ostream &os) const {
    os << data << " ";
}

template<typename T>
T Node<T>::get_data() {
    return data;
}

template<>
int Node<int>::get_data() {
    return data;
}

template<>
float Node<float>::get_data() {
    return data;
}

template<>
std::string Node<std::string>::get_data() {
    return data;
}