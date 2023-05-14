#ifndef OOP_POWER_H
#define OOP_POWER_H

#include "Expression.h"

class Power : public Expression {
public:
    Power(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_POWER_H
