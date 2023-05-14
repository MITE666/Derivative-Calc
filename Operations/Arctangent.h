#ifndef OOP_ARCTANGENT_H
#define OOP_ARCTANGENT_H

#include "Expression.h"

class Arctangent : public Expression {
public:
    Arctangent(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCTANGENT_H
