#ifndef OOP_ARCCOSINUS_H
#define OOP_ARCCOSINUS_H

#include "Expression.h"

class Arccosinus : public Expression {
public:
    Arccosinus(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCCOSINUS_H
