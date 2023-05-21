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

void Tree::Simplify(std::shared_ptr<BaseNode>& node) {
    if(node->get_left() != nullptr)
        Tree::Simplify(node->get_left());
    if(node->get_right() != nullptr)
        Tree::Simplify(node->get_right());
    auto string_ptr = std::dynamic_pointer_cast<Node<std::string>>(node);
    if(string_ptr) {
        if(string_ptr->get_data() == "+") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->get_left());
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->get_left());
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->get_right());
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>(int_ptr_left->get_data() + int_ptr_right->get_data());
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->get_data() + float_ptr_right->get_data());
                return;
            }
            if(int_ptr_left) {
                if(int_ptr_left->get_data() == 0) {
                    node = node->get_right();
                    return;
                }
            }
            if(int_ptr_right) {
                if(int_ptr_right->get_data() == 0) {
                    node = node->get_left();
                    return;
                }
            }
        } else if(string_ptr->get_data() == "-") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->get_left());
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->get_left());
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->get_right());
            auto string_ptr_left = std::dynamic_pointer_cast<Node<std::string>>(node->get_left());
            auto string_ptr_right = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>(int_ptr_left->get_data() - int_ptr_right->get_data());
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->get_data() - float_ptr_right->get_data());
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_left) {
                    if(int_ptr_right->get_data() == int_ptr_left->get_data())
                        node = std::make_shared<Node<int>>(0);
                    else if(int_ptr_right->get_data() == 0)
                        node = node->get_left();
                } else if(int_ptr_right->get_data() == 0)
                    node = node->get_left();
            } else if(string_ptr_left && string_ptr_right){
                if(string_ptr_right->get_data() == string_ptr_left->get_data())
                    node = std::make_shared<Node<int>>(0);
            }
        } else if(string_ptr->get_data() == "*") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->get_left());
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->get_left());
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->get_right());
            if(int_ptr_left && int_ptr_right) {
                node = std::make_shared<Node<int>>(int_ptr_right->get_data() * int_ptr_left->get_data());
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->get_data() * float_ptr_right->get_data());
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_right->get_data() == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
                else if(int_ptr_right->get_data() == 1) {
                    node = node->get_left();
                    return;
                }
            }
            if(int_ptr_left) {
                if(int_ptr_left->get_data() == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
                else if(int_ptr_left->get_data() == 1) {
                    node = node->get_right();
                    return;
                }
            }
        } else if(string_ptr->get_data() == "/") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->get_left());
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->get_left());
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->get_right());
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<float>>((float)(int_ptr_left->get_data() / int_ptr_right->get_data()));
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>((float)(float_ptr_left->get_data() * float_ptr_right->get_data()));
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_right->get_data() == 1) {
                    node = node->get_left();
                    return;
                }
            }
            if(int_ptr_left) {
                if(int_ptr_left->get_data() == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
            }
        } else if(string_ptr->get_data() == "ln") {
            auto int_ptr = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(int_ptr) {
                if(int_ptr->get_data() == 1)
                    node = std::make_shared<Node<int>>(0);
            } else if(string_ptr_arg) {
                if(string_ptr_arg->get_data() == "e")
                    node = std::make_shared<Node<int>>(1);
            }
        } else if(string_ptr->get_data() == "^") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->get_left());
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->get_right());
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->get_left());
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->get_right());
            auto string_ptr_left = std::dynamic_pointer_cast<Node<std::string>>(node->get_left());
            auto string_ptr_right = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>((int)pow(int_ptr_left->get_data(), int_ptr_right->get_data()));
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>((float)pow(float_ptr_left->get_data(), float_ptr_right->get_data()));
                return;
            }
            if(int_ptr_left) {
                if(int_ptr_left->get_data() == 1) {
                    node = std::make_shared<Node<int>>(1);
                    return;
                }
                else if(int_ptr_left->get_data() == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
            }
            if(int_ptr_right) {
                if(int_ptr_right->get_data() == 1) {
                    node = node->get_left();
                    return;
                }
                else if(int_ptr_right->get_data() == 0) {
                    node = std::make_shared<Node<int>>(1);
                    return;
                }
            }
            if(string_ptr_right && string_ptr_left)
                if(string_ptr_left->get_data() == "e" && string_ptr_right->get_data() == "ln")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "sin") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "arcsin")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "cos") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "arccos")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "tan") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "arctan")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "cot") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "arccot")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "arcsin") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "sin")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "arccos") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "cos")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "arctan") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "tan")
                    node = node->get_right()->get_right();
        } else if(string_ptr->get_data() == "arccot") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->get_right());
            if(string_ptr_arg)
                if(string_ptr_arg->get_data() == "cot")
                    node = node->get_right()->get_right();
        }
    }

}