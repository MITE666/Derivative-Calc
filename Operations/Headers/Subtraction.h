#ifndef OOP_SUBTRACTION_H
#define OOP_SUBTRACTION_H

#include "Expression.h"

class Subtraction : public Expression {
public:
    explicit Subtraction(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_SUBTRACTION_H