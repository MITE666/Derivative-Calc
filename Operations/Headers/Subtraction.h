#ifndef OOP_SUBTRACTION_H
#define OOP_SUBTRACTION_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Subtraction : public Expression {
public:
    explicit Subtraction(std::shared_ptr<Node>& exp_);
    std::shared_ptr<Node> Differentiate(std::string &var) override;
};


#endif //OOP_SUBTRACTION_H
