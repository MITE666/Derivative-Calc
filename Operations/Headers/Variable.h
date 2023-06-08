#ifndef OOP_VARIABLE_H
#define OOP_VARIABLE_H

#include "Expression.h"
#include "Constant.h"

class Variable : public Expression {
public:
    explicit Variable(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
    void Simplify() override;
};


#endif //OOP_VARIABLE_H