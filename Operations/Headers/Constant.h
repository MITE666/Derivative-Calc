#ifndef OOP_CONSTANT_H
#define OOP_CONSTANT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Constant : public Expression {
public:
    explicit Constant(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_CONSTANT_H