#ifndef OOP_NODE_H
#define OOP_NODE_H

#include <iostream>
#include <memory>

class Node {
private:
    virtual void printNode(std::ostream &os) const = 0;

public:
    void* data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    explicit Node(void* data_);
    friend std::ostream &operator<<(std::ostream &os, const Node& node_);
    [[nodiscard]] virtual std::shared_ptr<Node> clone() const = 0;
    Node &operator=(const Node &other) = default;
    virtual ~Node() = default;
};


#endif //OOP_NODE_H