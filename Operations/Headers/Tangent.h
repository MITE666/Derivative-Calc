#ifndef OOP_TANGENT_H
#define OOP_TANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Tangent : public Expression {
public:
    explicit Tangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_TANGENT_H