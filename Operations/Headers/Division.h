#ifndef OOP_DIVISION_H
#define OOP_DIVISION_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Division : public Expression {
public:
    explicit Division(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_DIVISION_H