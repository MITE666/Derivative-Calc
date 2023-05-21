#ifndef OOP_EXPRESSION_H
#define OOP_EXPRESSION_H

#include "../../Node/Headers/Node.h"
#include <memory>

class Expression {
protected:
    std::shared_ptr<BaseNode>& exp;
public:
    explicit Expression(std::shared_ptr<BaseNode>& exp_);
    virtual void Differentiate(std::string &var) = 0;
    virtual ~Expression() = default;
};

extern std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr);

#endif //OOP_EXPRESSION_H