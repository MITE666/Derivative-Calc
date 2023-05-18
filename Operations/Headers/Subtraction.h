#ifndef OOP_SUBTRACTION_H
#define OOP_SUBTRACTION_H

#include "Expression.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Subtraction : public Expression {
public:
    explicit Subtraction(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_SUBTRACTION_H