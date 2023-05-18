#ifndef OOP_SINUS_H
#define OOP_SINUS_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Sinus : public Expression {
public:
    explicit Sinus(std::shared_ptr<Node>& exp_);
    std::shared_ptr<Node> Differentiate(std::string &var) override;
};


#endif //OOP_SINUS_H
