#ifndef OOP_LOGARITHM_H
#define OOP_LOGARITHM_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Logarithm : public Expression {
public:
    explicit Logarithm(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_LOGARITHM_H