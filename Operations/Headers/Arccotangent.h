#ifndef OOP_ARCCOTANGENT_H
#define OOP_ARCCOTANGENT_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"
#include "../../Node/Headers/IntNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Arccotangent : public Expression {
public:
    explicit Arccotangent(std::shared_ptr<Node>& exp_);
    std::shared_ptr<Node> Differentiate(std::string &var) override;
};


#endif //OOP_ARCCOTANGENT_H
