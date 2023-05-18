#ifndef OOP_BASENODE_H
#define OOP_BASENODE_H

#include <iostream>
#include <memory>

class BaseNode {
private:
    virtual void PrintNode(std::ostream &os) const = 0;
public:
    std::shared_ptr<BaseNode> left;
    std::shared_ptr<BaseNode> right;
    BaseNode();
    friend std::ostream &operator<<(std::ostream &os, const BaseNode& baseNode_);
    [[nodiscard]] virtual std::shared_ptr<BaseNode> clone() const = 0;
    virtual ~BaseNode() = default;
};


#endif //OOP_BASENODE_H
