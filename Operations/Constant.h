#ifndef OOP_CONSTANT_H
#define OOP_CONSTANT_H

#include "Expression.h"
#include "../Node/IntNode.h"

class Constant : public Expression {
public:
    Constant(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_CONSTANT_H