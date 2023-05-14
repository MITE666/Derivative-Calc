#ifndef OOP_ARCCOTANGENT_H
#define OOP_ARCCOTANGENT_H

#include "Expression.h"

class Arccotangent : public Expression {
public:
    Arccotangent(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCCOTANGENT_H
