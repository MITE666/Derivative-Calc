#ifndef OOP_BASENODE_H
#define OOP_BASENODE_H

#include <iostream>
#include <memory>

class BaseNode {
private:
    virtual void PrintNode(std::ostream &os) const = 0;
    std::shared_ptr<BaseNode> left;
    std::shared_ptr<BaseNode> right;
    static int nr_parentheses;
public:
    BaseNode();
    friend std::ostream &operator<<(std::ostream &os, const BaseNode& baseNode_);
    [[nodiscard]] virtual std::shared_ptr<BaseNode> clone() const = 0;
    virtual ~BaseNode() = default;
    std::shared_ptr<BaseNode>& get_left();
    std::shared_ptr<BaseNode>& get_right();
    void set_left(std::shared_ptr<BaseNode> left_);
    void set_right(std::shared_ptr<BaseNode> right_);
};


#endif //OOP_BASENODE_H
