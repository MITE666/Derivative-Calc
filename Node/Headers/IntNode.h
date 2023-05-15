#ifndef OOP_INTNODE_H
#define OOP_INTNODE_H

#include "Node.h"

class IntNode : public Node {
private:
    void printNode(std::ostream &os) const override;
public:
    explicit IntNode(int data_);
    [[nodiscard]] std::shared_ptr<Node> clone() const override;
};


#endif //OOP_INTNODE_H
