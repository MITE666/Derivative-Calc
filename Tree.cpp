#include "Tree.h"

Tree::Tree(std::string &expression_) : expression(std::move(expression_)) {
    std::stack<std::shared_ptr<Node>> newStack;
    std::istringstream iss(expression);
    std::vector<std::string> elements;
    std::string element;
    while(std::getline(iss, element, ' ')) {
        elements.emplace_back(element);
    }
    for(const auto& elem : elements) {
        if(isInt(elem)) {
            int i = std::stoi(elem);
            std::shared_ptr<Node> ptr;
            ptr = std::make_shared<IntNode>(i);
            queue.push(ptr);
        } else if(isFloat(elem)) {
            float f = std::stof(elem);
            std::shared_ptr<Node> ptr;
            ptr = std::make_shared<FloatNode>(f);
            queue.push(ptr);
        } else {
            std::shared_ptr<Node> ptr;
            ptr = std::make_shared<StringNode>(elem);
            if(ptr->data == "(") {
                newStack.push(ptr);
            } else if(ptr->data == ")") {
                while(newStack.top()->data != "(") {
                    queue.push(newStack.top());
                    newStack.pop();
                }
                newStack.pop();
            } else if(priority.count(*(std::string*)ptr->data)){
                if(!newStack.empty())
                    while((!newStack.empty() || newStack.top()->data != "(") && priority[*(std::string*)ptr->data] <= priority[*(std::string*)newStack.top()->data]) {
                        queue.push(newStack.top());
                        newStack.pop();
                    }
                newStack.push(ptr);
            } else {
                queue.push(ptr);
            }
        }
    }
    while(!newStack.empty()) {
        queue.push(newStack.top());
        newStack.pop();
    }
}

bool Tree::isInt(const std::string& elem) {
    for(char c : elem) {
        if(!isdigit(c))
            return false;
    }
    return true;
}

bool Tree::isFloat(const std::string& elem) {
    int dotCount = 0;
    for(char c : elem) {
        if(!isdigit(c)) {
            if(c == '.')
                ++dotCount;
            else return false;
        }
        if(dotCount > 1)
            return false;
    }
    return true;
}

void Tree::Convert(std::queue<std::shared_ptr<Node>> queue_) {
    std::stack<std::shared_ptr<Node>> stack;
    while(!queue_.empty()) {
        std::shared_ptr<Node> ptr = queue_.front();
        queue_.pop();
        std::shared_ptr<IntNode> int_ptr = std::dynamic_pointer_cast<IntNode>(ptr);
        std::shared_ptr<FloatNode> float_ptr = std::dynamic_pointer_cast<FloatNode>(ptr);
        if(int_ptr || float_ptr) {
            stack.push(ptr);
        } else {
            if(ptr->data == "+" || ptr->data == "-" || ptr->data == "/" || ptr->data == "*" || ptr->data == "^") {
                std::shared_ptr<Node> right_ptr = stack.top();
                stack.pop();
                std::shared_ptr<Node> left_ptr = stack.top();
                stack.pop();
                ptr->right = right_ptr;
                ptr->left = left_ptr;
                stack.push(ptr);
            } else if(ptr->data == "sin" || ptr->data == "cos" || ptr->data == "tan" || ptr->data == "cot" || ptr->data == "ln" || ptr->data == "arcsin" || ptr->data == "arccos" || ptr->data == "arctan" || ptr->data == "arccot") {
                std::shared_ptr<Node> new_ptr = stack.top();
                stack.pop();
                ptr->right = new_ptr;
                stack.push(ptr);
            } else {
                stack.push(ptr);
            }
        }
    }
    root = stack.top();
    stack.pop();
}

void Tree::PrintQueue() {
    while(!queue.empty()) {
        std::shared_ptr<Node> ptr = queue.front();
        std::cout << ptr << " ";
        queue.pop();
    }
}
