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
            if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->data == "(\0") {
                newStack.push(ptr);
            } else if(std::dynamic_pointer_cast<Node<std::string>>(ptr)->data == ")\0") {
                while(std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->data != "(\0") {
                    queue.push(newStack.top());
                    newStack.pop();
                }
                newStack.pop();
            } else if(priority.count(std::dynamic_pointer_cast<Node<std::string>>(ptr)->data)){
                if(!newStack.empty())
                    while(!newStack.empty() && std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->data != "(\0" && priority[std::dynamic_pointer_cast<Node<std::string>>(ptr)->data] <= priority[std::dynamic_pointer_cast<Node<std::string>>(newStack.top())->data]) {
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
            if(std::count(binaryOp.begin(), binaryOp.end(), std::dynamic_pointer_cast<Node<std::string>>(ptr)->data)) {
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> right_ptr = stack.top();
                stack.pop();
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> left_ptr = stack.top();
                stack.pop();
                ptr->right = right_ptr;
                ptr->left = left_ptr;
                stack.push(ptr);
            } else if(std::count(unaryOp.begin(), unaryOp.end(), std::dynamic_pointer_cast<Node<std::string>>(ptr)->data)) {
                if(stack.empty())
                    throw EmptyStackException();
                std::shared_ptr<BaseNode> new_ptr = stack.top();
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

std::ostream &operator<<(std::ostream &os, const Tree &tree_) {
    os << *tree_.root;
    return os;
}

void Tree::Simplify(std::shared_ptr<BaseNode>& node) {
    if(node->left != nullptr)
        Tree::Simplify(node->left);
    if(node->right != nullptr)
        Tree::Simplify(node->right);
    auto string_ptr = std::dynamic_pointer_cast<Node<std::string>>(node);
    if(string_ptr) {
        if(string_ptr->data == "+\0") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->left);
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->left);
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->right);
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>(int_ptr_left->data + int_ptr_right->data);
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->data + float_ptr_right->data);
                return;
            }
            if(int_ptr_left) {
                if(int_ptr_left->data == 0) {
                    node = node->right;
                    return;
                }
            }
            if(int_ptr_right) {
                if(int_ptr_right->data == 0) {
                    node = node->left;
                    return;
                }
            }
        } else if(string_ptr->data == "-\0") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->left);
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->left);
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->right);
            auto string_ptr_left = std::dynamic_pointer_cast<Node<std::string>>(node->left);
            auto string_ptr_right = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>(int_ptr_left->data - int_ptr_right->data);
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->data - float_ptr_right->data);
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_left) {
                    if(int_ptr_right->data == int_ptr_left->data)
                        node = std::make_shared<Node<int>>(0);
                    else if(int_ptr_right->data == 0)
                        node = node->left;
                } else if(int_ptr_right->data == 0)
                    node = node->left;
            } else if(string_ptr_left && string_ptr_right){
                if(string_ptr_right->data == string_ptr_left->data)
                    node = std::make_shared<Node<int>>(0);
            }
        } else if(string_ptr->data == "*\0") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->left);
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->left);
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->right);
            if(int_ptr_left && int_ptr_right) {
                node = std::make_shared<Node<int>>(int_ptr_right->data * int_ptr_left->data);
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>(float_ptr_left->data * float_ptr_right->data);
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_right->data == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
                else if(int_ptr_right->data == 1) {
                    node = node->left;
                    return;
                }
            }
            if(int_ptr_left) {
                if(int_ptr_left->data == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
                else if(int_ptr_left->data == 1) {
                    node = node->right;
                    return;
                }
            }
        } else if(string_ptr->data == "/\0") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->left);
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->left);
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->right);
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<float>>((float)(int_ptr_left->data / int_ptr_right->data));
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>((float)(float_ptr_left->data * float_ptr_right->data));
                return;
            }
            if(int_ptr_right) {
                if(int_ptr_right->data == 1) {
                    node = node->left;
                    return;
                }
            }
            if(int_ptr_left) {
                if(int_ptr_left->data == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
            }
        } else if(string_ptr->data == "ln\0") {
            auto int_ptr = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(int_ptr) {
                if(int_ptr->data == 1)
                    node = std::make_shared<Node<int>>(0);
            } else if(string_ptr_arg) {
                if(string_ptr_arg->data == "e\0")
                    node = std::make_shared<Node<int>>(1);
            }
        } else if(string_ptr->data == "^\0") {
            auto int_ptr_left = std::dynamic_pointer_cast<Node<int>>(node->left);
            auto int_ptr_right = std::dynamic_pointer_cast<Node<int>>(node->right);
            auto float_ptr_left = std::dynamic_pointer_cast<Node<float>>(node->left);
            auto float_ptr_right = std::dynamic_pointer_cast<Node<float>>(node->right);
            auto string_ptr_left = std::dynamic_pointer_cast<Node<std::string>>(node->left);
            auto string_ptr_right = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(int_ptr_right && int_ptr_left) {
                node = std::make_shared<Node<int>>((int)pow(int_ptr_left->data, int_ptr_right->data));
                return;
            }
            if(float_ptr_right && float_ptr_left) {
                node = std::make_shared<Node<float>>((float)pow(float_ptr_left->data, float_ptr_right->data));
                return;
            }
            if(int_ptr_left) {
                if(int_ptr_left->data == 1) {
                    node = std::make_shared<Node<int>>(1);
                    return;
                }
                else if(int_ptr_left->data == 0) {
                    node = std::make_shared<Node<int>>(0);
                    return;
                }
            }
            if(int_ptr_right) {
                if(int_ptr_right->data == 1) {
                    node = node->left;
                    return;
                }
                else if(int_ptr_right->data == 0) {
                    node = std::make_shared<Node<int>>(1);
                    return;
                }
            }
            if(string_ptr_right && string_ptr_left)
                if(string_ptr_left->data == "e\0" && string_ptr_right->data == "ln\0")
                    node = node->right->right;
        } else if(string_ptr->data == "sin\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "arcsin\0")
                    node = node->right->right;
        } else if(string_ptr->data == "cos\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "arccos\0")
                    node = node->right->right;
        } else if(string_ptr->data == "tan\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "arctan\0")
                    node = node->right->right;
        } else if(string_ptr->data == "cot\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "arccot\0")
                    node = node->right->right;
        } else if(string_ptr->data == "arcsin\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "sin\0")
                    node = node->right->right;
        } else if(string_ptr->data == "arccos\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "cos\0")
                    node = node->right->right;
        } else if(string_ptr->data == "arctan\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "tan\0")
                    node = node->right->right;
        } else if(string_ptr->data == "arccot\0") {
            auto string_ptr_arg = std::dynamic_pointer_cast<Node<std::string>>(node->right);
            if(string_ptr_arg)
                if(string_ptr_arg->data == "cot\0")
                    node = node->right->right;
        }
    }

}