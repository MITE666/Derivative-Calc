#ifndef OOP_NODE_H
#define OOP_NODE_H

#include "BaseNode.h"
#include <utility>

template <typename T>
class Node : public BaseNode {
private:
    void PrintNode(std::ostream& os) const override;
public:
    T data;
    explicit Node(T data_);
    [[nodiscard]] std::shared_ptr<BaseNode> clone() const override;
};


#endif //OOP_NODE_H