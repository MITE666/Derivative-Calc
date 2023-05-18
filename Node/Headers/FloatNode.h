#ifndef OOP_FLOATNODE_H
#define OOP_FLOATNODE_H

#include "Node.h"

class FloatNode : public Node{
private:
    void printNode(std::ostream &os) const override;
public:
    explicit FloatNode(float data_);
    [[nodiscard]] std::shared_ptr<Node> clone() const override;
};


#endif //OOP_FLOATNODE_H