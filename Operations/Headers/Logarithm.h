#ifndef OOP_LOGARITHM_H
#define OOP_LOGARITHM_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Logarithm : public Expression {
public:
    Logarithm(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_LOGARITHM_H
