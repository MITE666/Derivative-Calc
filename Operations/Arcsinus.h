#ifndef OOP_ARCSINUS_H
#define OOP_ARCSINUS_H

#include "Expression.h"

class Arcsinus :public Expression {
public:
    Arcsinus(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCSINUS_H
