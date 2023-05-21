#include "EmptyStackException.h"

const char *EmptyStackException::what() const noexcept {
    return "Expresia introdusa nu e corecta!\n";
}
