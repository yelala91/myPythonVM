#include "object.hpp"

std::ostream& mpvm::operator<<(std::ostream& out, const Object& obj) {
    return obj._display(out);
}