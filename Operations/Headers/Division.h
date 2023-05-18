#ifndef OOP_DIVISION_H
#define OOP_DIVISION_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"
#include "../../Node/Headers/IntNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Division : public Expression {
public:
    explicit Division(std::shared_ptr<Node>& exp_);
    std::shared_ptr<Node> Differentiate(std::string &var) override;
};


#endif //OOP_DIVISION_H
