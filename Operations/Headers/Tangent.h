#ifndef OOP_TANGENT_H
#define OOP_TANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Tangent : public Expression {
public:
    explicit Tangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_TANGENT_H