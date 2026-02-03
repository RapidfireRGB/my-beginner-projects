#ifndef HELPERFUNCTIONS_PTR_FUNC_H
#define HELPERFUNCTIONS_PTR_FUNC_H
#include <string>
#include <iostream>
#include <sstream>

// Prints the memory address of a variable given a pointer.
template <typename T>
void print_address(const T* pointer) {
    std::cout << &pointer;
}

// Prints the memory address of a variable with n number of whitespaces at the end.
template <typename T>
void printtab_address(const T* pointer, const short n=4) {
    std::cout << &pointer << std::string(n, ' ');
}

// Prints the memory address of a variable with a linebreak at the end
template <typename T>
void printbr_address(const T* pointer) {
    std::cout << &pointer << '\n';
}

// Returns true if a pointer is null
template <typename T>
bool is_null(const T* pointer) {
    return pointer == nullptr;
}

// Returns the string representation of a pointer
template <typename T>
std::string address_string(T* pointer) {
    std::ostringstream address_string;
    address_string << pointer;
    return address_string.str();
}

// Swaps memory addresses of two pointers
template <typename T>
void swap_address(T* ptr_1, T* ptr_2) {
    std::swap(&ptr_1, &ptr_2);
}

// Returns true if two pointers point to the same address.
template <typename T>
bool ptr_equal(const T* ptr_1, const T* ptr_2) {
    return &ptr_1 == &ptr_2;
}

// Returns the value stored at a pointer's address if it is not null.
template <typename T>
T safe_dereference(const T* pointer) {
    T result;
    if (pointer != nullptr) {
        result = *pointer;
    }
    return result;
}

// Returns the sum of the value at two pointers.
template <typename T>
T ptr_sum(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    T sum = *ptr_1 + *ptr_2;
    return sum;
}

// Returns the product of the value at two pointers.
template <typename T>
T ptr_product(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    T product = *ptr_1 * *ptr_2;
    return product;
}

// Returns the quotient of the value at two pointers.
template <typename T>
T ptr_quotient(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    T quotient = *ptr_1 / *ptr_2;
    return quotient;
}

// Returns the remainder from dividing the value at two pointers.
template <typename T>
T ptr_remainder(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    T remainder = *ptr_1 % *ptr_2;
    return remainder;
}

// Returns the difference between the value at two pointers.
template <typename T>
T ptr_difference(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    T difference = *ptr_1 - *ptr_2;
    return difference;
}

// Moves a pointer by n number of elements
template <typename T>
void move_ptr(T* pointer, const size_t n) {
    if (is_null(pointer) || is_null(pointer + n)) {
        return;
    }
    pointer += n;
}

// Sets a pointer to null by reference to a pointer
template <typename T>
void null_by_reference(T*& pointer) {
    if (is_null(pointer)) {
        return;
    }
    pointer = nullptr;
}

// Moves a pointer by n number of elements, up to a boundary.
template <typename T>
void bounded_move_ptr(T* pointer, size_t n, const size_t upper_bound) {
    if (n > upper_bound) {
        n = upper_bound;
    }
    if (pointer == nullptr || pointer + n == nullptr ) {
        return;
    }
    pointer += n;
}

// Returns the distance between two pointers.
template <typename T>
size_t ptr_distance(T* ptr_1, T* ptr_2) {
    if (is_null(ptr_1) || is_null(ptr_2)) {
        return 0;
    }
    const size_t distance = ptr_1 - ptr_2;
    return distance;
}

#endif //HELPERFUNCTIONS_PTR_FUNC_H