#ifndef OOP_EXPRESSION_H
#define OOP_EXPRESSION_H

#include "../../Node/Headers/Node.h"
#include <memory>

class Expression {
protected:
    std::shared_ptr<Node> DeepCopy(std::shared_ptr<Node> node);
public:
    std::shared_ptr<Node>& exp;
    explicit Expression(std::shared_ptr<Node>& exp_);
    virtual void Differentiate(std::string &var) = 0;
    virtual ~Expression() = default;
};


#endif //OOP_EXPRESSION_H