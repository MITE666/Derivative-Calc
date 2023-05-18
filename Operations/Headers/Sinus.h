#ifndef OOP_SINUS_H
#define OOP_SINUS_H

#include "Expression.h"
#include "../../Node/Headers/Node.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

class Sinus : public Expression {
public:
    explicit Sinus(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_SINUS_H