#ifndef OOP_STRINGNODE_H
#define OOP_STRINGNODE_H

#include "Node.h"

class StringNode : public Node {
private:
    void printNode(std::ostream &os) const override;
public:
    explicit StringNode(const std::string &data_);
    [[nodiscard]] std::shared_ptr<Node> clone() const override;
};


#endif //OOP_STRINGNODE_H