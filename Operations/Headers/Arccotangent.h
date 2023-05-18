#ifndef OOP_ARCCOTANGENT_H
#define OOP_ARCCOTANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Arccotangent : public Expression {
public:
    explicit Arccotangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCCOTANGENT_H