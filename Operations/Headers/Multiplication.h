#ifndef OOP_MULTIPLICATION_H
#define OOP_MULTIPLICATION_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Multiplication : public Expression {
public:
    explicit Multiplication(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_MULTIPLICATION_H