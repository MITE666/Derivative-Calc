#ifndef OOP_POWER_H
#define OOP_POWER_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

class Power : public Expression {
public:
    explicit Power(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_POWER_H