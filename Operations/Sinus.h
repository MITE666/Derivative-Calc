#ifndef OOP_SINUS_H
#define OOP_SINUS_H

#include "Expression.h"

class Sinus : public Expression {
public:
    Sinus(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_SINUS_H
