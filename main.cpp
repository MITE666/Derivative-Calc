#include "Tree.h"
#include "Node/Headers/Node.h"
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

std::shared_ptr<Expression> ExpressionType(std::shared_ptr<BaseNode>& ptr) {
    std::shared_ptr<BaseNode> int_node = std::dynamic_pointer_cast<Node<int>>(ptr);
    std::shared_ptr<BaseNode> float_node = std::dynamic_pointer_cast<Node<float>>(ptr);
    if(int_node || float_node)
        return std::make_shared<Constant>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "+")
        return std::make_shared<Addition>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "-")
        return std::make_shared<Subtraction>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "*")
        return std::make_shared<Multiplication>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "/")
        return std::make_shared<Division>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "ln")
        return std::make_shared<Logarithm>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "^")
        return std::make_shared<Power>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "sin")
        return std::make_shared<Sinus>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "cos")
        return std::make_shared<Cosinus>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "tan")
        return std::make_shared<Tangent>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "cot")
        return std::make_shared<Cotangent>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "arcsin")
        return std::make_shared<Arcsinus>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "arccos")
        return std::make_shared<Arccosinus>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "arctan")
        return std::make_shared<Arctangent>(ptr);
    else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "arccot")
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
    Tree expression {expr};
    //std::cout << expression << "\n";
    std::shared_ptr<Expression> deriv = ExpressionType(expression.root);
    deriv->Differentiate(variable);
    deriv->Simplify();
    std::cout << *expression.root;
    int exit;
    std::cout << "\nscrieti 0 pentru a termina programul\n";
    while(true) {
        std::cin >> exit;
        if(exit == 0)
            break;
    }
    return 0;
}