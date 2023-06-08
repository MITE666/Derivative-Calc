#ifndef OOP_COTANGENT_H
#define OOP_COTANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Cotangent : public Expression {
public:
    explicit Cotangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_COTANGENT_H