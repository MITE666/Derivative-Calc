#ifndef OOP_COSINUS_H
#define OOP_COSINUS_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Cosinus : public Expression {
public:
    explicit Cosinus(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_COSINUS_H