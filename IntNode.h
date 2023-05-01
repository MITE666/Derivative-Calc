#ifndef OOP_INTNODE_H
#define OOP_INTNODE_H

#include "Node.h"

class IntNode : public Node {
private:
    void printNode(std::ostream &os) const override;
public:
    IntNode(int data_);
    std::shared_ptr<Node> clone() const override;
};


#endif //OOP_INTNODE_H
