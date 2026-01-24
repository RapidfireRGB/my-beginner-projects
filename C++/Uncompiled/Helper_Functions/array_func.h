#ifndef HELPERFUNCTIONS_ARRAY_FUNC_H
#define HELPERFUNCTIONS_ARRAY_FUNC_H
//#include <array>
#include <iostream>
#include <string>
#include <vector>
/*
 *  Note that these functions take pointer to first array element,
 *  and array size for their parameters.
 */

// Prints contents of an array.
template <typename T>
void print_arr(const T *array, const int size) {
    for (int i = 0; i <= size-1; i++) {
        std::cout << array[i];
    }
}

// Prints contents of an array separated by linebreaks.
template <typename T>
void printbr_arr(const T *array, const int size) {
    for (int i = 0; i <= size-1; i++) {
        std::cout << array[i] << "\n";
    }
}

// Prints contents of an array separated by n number of whitespaces (default 4)
template <typename T>
void printtab_arr(const T *array, const int size, const short n=4) {
    for (int i = 0; i <= size-1; i++) {
        std::cout << array[i] << std::to_string(n, ' ');
    }
}

// Checks whether an array has a specified element.
template <typename T>
bool contains(const T *array, const int size, const T element) {
    if (size == 0) {
        return false;
    }
    for (int i = 0; i <= size-1; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Fills array with a specified value.
template <typename T>
void fill(const T *array, const int size, const T value) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i <= size-1; i++) {
        array[i] = value;
    }
}

// Fills array with a value if condition is met
template <typename T>
void fill_if(const T *array, const int size, const T value, const bool condition) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i <= size-1; i++) {
        if (condition == true) {
            array[i] = value;
        }
    }
}

// Reverses the elements of an array
template <typename T>
void reverse(const T *array, const int size) {
    std::vector<T> temp;
    for (int i = size-1; i >= 0; i--) {
        temp.push_back(array[i]);
    }
    for (int j = 0; j <= size-1; j++) {
        array[j] = temp[j];
    }
}

// Returns the first index position of a given value, or zero if not found.
template <typename T>
int first_index(const T *array, const int size, const T value) {
    if (size == 0) {
        return 0;
    }
    for (int i = 0; i <= size-1; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return 0;
}

// Returns a vector of all indices of a value.
template <typename T>
std::vector<T> indices(const T *array, const int size, const T value) {
    std::vector<T> new_vec;
    if (size == 0) {
        return new_vec;
    }
    for (int i = 0; i <= size-1; i++) {
        if (array[i] == value) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns the maximum value in an array.
template <typename T>
T max(const T *array, const int size) {
    T maximum = array[0];
    for (int i = 1; i <= size-1; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

// Returns the minimum value in an array
template <typename T>
T min(const T *array, const int size) {
    T minimum = array[0];
    for (int i = 1; i <= size-1; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

// Returns a vector with an array's elements.
template <typename T>
std::vector<T> arr_to_vec(const T *array, const int size) {
    std::vector<T> new_vec;
    if (size == 0) {
        return new_vec;
    }
    for (int i = 0; i <= size-1; i++) {
        new_vec.push_back(array[i]);
    }
    return new_vec;
}

// Zero out a numerical array
template <typename T>
void zero(const T *array, const int size) {
    for (int i = 0; i <= size-1; i++) {
        array[i] = 0;
    }
}

// Checks if two arrays are identical in size, elements, and element order.
template <typename T>
bool is_copy(const T *array_1, const int size_1, const T *array_2, const int size_2) {
    if (size_1 != size_2) {
        return false;
    }
    if (size_1 == 0 && size_2 == 0) {
        return false;
    }
    for (int i = 0; i <= size_1; i++) {
        if (array_1[i] != array_2[i]) {
            return false;
        }
    }
    return true;
}

// Sorts a numerical array in descending order (greatest to least)
template <typename T>
void sort_desc(const T *array, const int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i <= size-2; i++) {
        if (array[i] < array[i+1]) {

            T temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;

            i--;
        }
    }
}

// Sorts a numerical array in ascending order (least to greatest)
template <typename T>
void sort_asc(const T *array, const int size) {
    if (size == 0) {
        return;
    }
    for (int i = 0; i <= size-2; i++) {
        if (array[i] > array[i+1]) {

            T temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;

            i--;
        }
    }
}

// Checks whether a numerical array is sorted in descending order
template <typename T>
bool is_sorted_desc(const T *array, const int size) {
    if (size == 0) {
        return false;
    }
    for (int i = 0; i <= size-2; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}

// Checks wehter a numerical array is sorted in ascending order
template <typename T>
bool is_sorted_asc(const T *array, const int size) {
    if (size == 0) {
        return false;
    }
    for (int i = 0; i <= size-2; i++) {
        if (array[i] < array[i+1]) {
            return false;
        }
    }
    return true;
}

#endif //HELPERFUNCTIONS_ARRAY_FUNC_H