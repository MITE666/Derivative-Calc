#ifndef OOP_EXPRESSION_H
#define OOP_EXPRESSION_H

#include "Tree.h"
#include <memory>

class Expression {
public:
    virtual std::shared_ptr<Expression> clone() = 0;

    virtual ~Expression() = default;
};


#endif //OOP_EXPRESSION_H
