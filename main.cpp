#include "Tree.h"
#include "Operations/Headers/Addition.h"
#include "Operations/Headers/Arccosinus.h"
#include "Operations/Headers/Arccotangent.h"
#include "Operations/Headers/Arcsinus.h"
#include "Operations/Headers/Arctangent.h"
#include "Operations/Headers/Constant.h"
#include "Operations/Headers/Cosinus.h"
#include "Operations/Headers/Cotangent.h"
#include "Operations/Headers/Division.h"
#include "Operations/Headers/Logarithm.h"
#include "Operations/Headers/Multiplication.h"
#include "Operations/Headers/Power.h"
#include "Operations/Headers/Sinus.h"
#include "Operations/Headers/Subtraction.h"
#include "Operations/Headers/Tangent.h"
#include "Operations/Headers/Variable.h"

std::shared_ptr<Expression> ExpressionType(std::shared_ptr<Node>& ptr) {
    std::shared_ptr<Node> int_node = std::dynamic_pointer_cast<IntNode>(ptr);
    std::shared_ptr<Node> float_node = std::dynamic_pointer_cast<FloatNode>(ptr);
    if(int_node || float_node)
        return std::make_shared<Constant>(ptr);
    else if(*(std::string*)ptr->data == "+\0")
        return std::make_shared<Addition>(ptr);
    else if(*(std::string*)ptr->data == "-\0")
        return std::make_shared<Subtraction>(ptr);
    else if(*(std::string*)ptr->data == "*\0")
        return std::make_shared<Multiplication>(ptr);
    else if(*(std::string*)ptr->data == "/\0")
        return std::make_shared<Division>(ptr);
    else if(*(std::string*)ptr->data == "ln\0")
        return std::make_shared<Logarithm>(ptr);
    else if(*(std::string*)ptr->data == "^\0")
        return std::make_shared<Power>(ptr);
    else if(*(std::string*)ptr->data == "sin\0")
        return std::make_shared<Sinus>(ptr);
    else if(*(std::string*)ptr->data == "cos\0")
        return std::make_shared<Cosinus>(ptr);
    else if(*(std::string*)ptr->data == "tan\0")
        return std::make_shared<Tangent>(ptr);
    else if(*(std::string*)ptr->data == "cot\0")
        return std::make_shared<Cotangent>(ptr);
    else if(*(std::string*)ptr->data == "arcsin\0")
        return std::make_shared<Arcsinus>(ptr);
    else if(*(std::string*)ptr->data == "arccos\0")
        return std::make_shared<Arccosinus>(ptr);
    else if(*(std::string*)ptr->data == "arctan\0")
        return std::make_shared<Arctangent>(ptr);
    else if(*(std::string*)ptr->data == "arccot\0")
        return std::make_shared<Arccotangent>(ptr);
    else
        return std::make_shared<Variable>(ptr);
}

int main() {
    std::cout << "Introduceti functia pe care doriti sa o derivati:\n";
    std::string expr, variable;
    std::getline(std::cin, expr);
    std::cout << "In baza carei variabile doriti sa derivati?\n";
    std::getline(std::cin, variable);
    Tree expression = Tree(expr);
    //std::cout << expression << "\n";
    std::shared_ptr<Expression> deriv = ExpressionType(expression.root);
    auto final_root = deriv->Differentiate(variable);
    std::cout << *final_root;
    int exit;
    std::cout << "\nscrieti 0 pentru a termina programul\n";
    while(true) {
        std::cin >> exit;
        if(exit == 0)
            break;
    }
    return 0;
}
