#ifndef OOP_LOGARITHM_H
#define OOP_LOGARITHM_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Logarithm : public Expression {
public:
    explicit Logarithm(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_LOGARITHM_H