#ifndef OOP_COTANGENT_H
#define OOP_COTANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Cotangent : public Expression {
public:
    explicit Cotangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_COTANGENT_H