#ifndef OOP_POWER_H
#define OOP_POWER_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"
#include "../../Node/Headers/IntNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Power : public Expression {
public:
    explicit Power(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_POWER_H
