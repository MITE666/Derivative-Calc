#ifndef OOP_LOGARITHM_H
#define OOP_LOGARITHM_H

#include "Expression.h"

class Logarithm : public Expression {
public:
    Logarithm(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_LOGARITHM_H
