#ifndef OOP_ADDITION_H
#define OOP_ADDITION_H

#include "Expression.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Addition : public Expression {
public:
    Addition(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ADDITION_H
