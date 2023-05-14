#ifndef OOP_DIVISION_H
#define OOP_DIVISION_H

#include "Expression.h"
#include "../Node/StringNode.h"

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr);

class Division : public Expression {
public:
    Division(std::shared_ptr<Node>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_DIVISION_H
