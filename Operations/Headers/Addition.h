#ifndef OOP_ADDITION_H
#define OOP_ADDITION_H

#include "Expression.h"
#include "../../Node/Headers/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Addition : public Expression {
public:
    explicit Addition(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ADDITION_H
