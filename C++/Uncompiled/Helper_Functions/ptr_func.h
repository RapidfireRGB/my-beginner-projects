#ifndef HELPERFUNCTIONS_PTR_FUNC_H
#define HELPERFUNCTIONS_PTR_FUNC_H
#include <string>
#include <sstream>

// Returns the memory address of a variable given a pointer.
template <typename T>
std::string address_of(const T *pointer) {
    std::ostringstream address_str;
    // Static cast to treat pointer as memory address; writes to new string with insertion '<<' operator.
    address_str << static_cast<const void *>(pointer);
    return address_str.str();
}

// Returns true if a pointer is null
template <typename T>
bool is_null(const T *pointer) {
    if (pointer == nullptr) {
        return true;
    }
    return false;
}

#endif //HELPERFUNCTIONS_PTR_FUNC_H