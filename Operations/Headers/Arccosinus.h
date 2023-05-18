#ifndef OOP_ARCCOSINUS_H
#define OOP_ARCCOSINUS_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"
#include "../../Node/Headers/IntNode.h"
#include "../../Node/Headers/FloatNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Arccosinus : public Expression {
public:
    explicit Arccosinus(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ARCCOSINUS_H