#ifndef OOP_DIVISION_H
#define OOP_DIVISION_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Division : public Expression {
public:
    explicit Division(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_DIVISION_H