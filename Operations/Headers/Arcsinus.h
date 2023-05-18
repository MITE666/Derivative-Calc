#ifndef OOP_ARCSINUS_H
#define OOP_ARCSINUS_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"
#include "../../Node/Headers/IntNode.h"
#include "../../Node/Headers//FloatNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Arcsinus :public Expression {
public:
    explicit Arcsinus(std::shared_ptr<Node>& exp_);
    std::shared_ptr<Node> Differentiate(std::string &var) override;
};


#endif //OOP_ARCSINUS_H
