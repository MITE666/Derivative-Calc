#ifndef OOP_ARCTANGENT_H
#define OOP_ARCTANGENT_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Arctangent : public Expression {
public:
    explicit Arctangent(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCTANGENT_H