#ifndef OOP_ADDITION_H
#define OOP_ADDITION_H

#include "Expression.h"

class Addition : public Expression {
public:
    explicit Addition(std::shared_ptr<BaseNode>& exp_);
    void Differentiate(std::string &var) override;
};


#endif //OOP_ADDITION_H