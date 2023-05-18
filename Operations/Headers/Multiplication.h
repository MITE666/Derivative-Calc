#ifndef OOP_MULTIPLICATION_H
#define OOP_MULTIPLICATION_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Multiplication : public Expression {
public:
    explicit Multiplication(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_MULTIPLICATION_H