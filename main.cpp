#include "Expression.h"

int main() {
    std::cout << "Introduceti functia pe care doriti sa o derivati: ";
    std::string expr;
    std::getline(std::cin, expr);
    Tree expression = Tree(expr);
    expression.PrintQueue();
    std::cout << "\n";
    expression.PrintTree();
    return 0;
}
