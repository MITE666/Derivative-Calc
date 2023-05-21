#ifndef OOP_EMPTYSTACKEXCEPTION_H
#define OOP_EMPTYSTACKEXCEPTION_H

#include <exception>
#include <stack>

class EmptyStackException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //OOP_EMPTYSTACKEXCEPTION_H
