#include "Expression.h"

int main() {
    std::cout << "Introduceti functia pe care doriti sa o derivati: ";
    std::string expr;
    //std::getline(std::cin, expr);
    //Tree expression = Tree(expr);
    //expression.PrintQueue();
    std::shared_ptr<Node> node = std::make_shared<StringNode>("rofl");
    std::shared_ptr<Node> node2 = std::make_shared<StringNode>("rofl2");
    std::cout << *node << *node2;
    return 0;
}
