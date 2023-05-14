#ifndef OOP_COSINUS_H
#define OOP_COSINUS_H

#include "Expression.h"

class Cosinus : public Expression {
public:
    Cosinus(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_COSINUS_H
