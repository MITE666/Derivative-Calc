#ifndef OOP_COTANGENT_H
#define OOP_COTANGENT_H

#include "Expression.h"

class Cotangent : public Expression {
public:
    Cotangent(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_COTANGENT_H
