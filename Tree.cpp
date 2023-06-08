#include "Tree.h"

Tree::Tree(std::string &expression_) : expression(expression_) {
    std::stack<std::shared_ptr<BaseNode>> newStack;
    std::istringstream iss(expression);
    std::vector<std::string> elements;
    std::string element;
    while(std::getline(iss, element, ' ')) {
        elements.emplace_back(element);
    }
    for(const auto& elem : elements) {
        if(isInt(elem)) {
            int i = std::stoi(elem);
            std::shared_ptr<BaseNode> ptr = std::make_shared<Node<int>>(i);
            queue.push(ptr);
        } else if(isFloat(elem)) {
            float f = std::stof(elem);
            std::shared_ptr<BaseNode> ptr = std::make_shared<Node<float>>(f);
            queue.push(ptr);
        } else {
            std::shared_ptr<BaseNode> ptr = std::make_shared<Node<std::string>>(elem);
            if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == "(") {
                newStack.push(ptr);
            } else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data() == ")") {
                while(std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->get_data() != "(") {
                    queue.push(newStack.top());
                    newStack.pop();
                }
                newStack.pop();
            } else if(priority.count(std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data())){
                if(!newStack.empty())
                    while(!newStack.empty() && std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->get_data() != "(" && priority[std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data()] <= priority[std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->get_data()]) {
                        queue.push(newStack.top());
                        newStack.pop();
                        if(newStack.empty())
                            break;
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
    try {
        Convert();
    } catch(EmptyStackException& e) {
        std::cout << e.what();
    }
}

bool Tree::isInt(const std::string& elem) {
    for (char c: elem) {
        if (!isdigit(c))
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

void Tree::Convert() {
    std::stack<std::shared_ptr<BaseNode>> stack;
    while(!queue.empty()) {
        std::shared_ptr<BaseNode> ptr = queue.front();
        queue.pop();
        std::shared_ptr<BaseNode> int_ptr = std::dynamic_pointer_cast<Node<int>>(ptr);
        std::shared_ptr<BaseNode> float_ptr = std::dynamic_pointer_cast<Node<float>>(ptr);
        if(int_ptr || float_ptr) {
            stack.push(ptr);
        } else {
            if(std::count(binaryOp.begin(), binaryOp.end(), std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data())) {
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> right_ptr = stack.top();
                stack.pop();
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> left_ptr = stack.top();
                stack.pop();
                ptr->set_right(right_ptr);
                ptr->set_left(left_ptr);
                stack.push(ptr);
            } else if(std::count(unaryOp.begin(), unaryOp.end(), std::dynamic_pointer_cast<Node<std::string>>(ptr)->get_data())) {
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> new_ptr = stack.top();
                stack.pop();
                ptr->set_right(new_ptr);
                stack.push(ptr);
            } else {
                stack.push(ptr);
            }
        }
    }
    root = stack.top();
    stack.pop();
}

std::ostream &operator<<(std::ostream &os, const Tree &tree_) {
    os << *tree_.root;
    return os;
}
