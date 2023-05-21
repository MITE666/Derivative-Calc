#ifndef OOP_ARCSINUS_H
#define OOP_ARCSINUS_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Arcsinus :public Expression {
public:
    explicit Arcsinus(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCSINUS_H