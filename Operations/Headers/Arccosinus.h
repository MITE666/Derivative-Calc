#ifndef OOP_ARCCOSINUS_H
#define OOP_ARCCOSINUS_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Arccosinus : public Expression {
public:
    explicit Arccosinus(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_ARCCOSINUS_H