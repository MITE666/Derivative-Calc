#ifndef OOP_TANGENT_H
#define OOP_TANGENT_H

#include "Expression.h"

class Tangent : public Expression {
public:
    Tangent(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_TANGENT_H
