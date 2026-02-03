#ifndef HELPERFUNCTIONS_ARRAY_FUNC_H
#define HELPERFUNCTIONS_ARRAY_FUNC_H
#include <iostream>
#include <string>
#include <vector>
/*
 *  Note that these functions take pointer to first array element,
 *  and array size for their parameters.
 */

// Prints contents of an array.
template <typename T>
void print_arr(const T *array, const size_t size) {
    for (size_t i = 0; i <= size-1; i++) {
        std::cout << array[i];
    }
}

// Prints contents of an array separated by linebreaks.
template <typename T>
void printbr_arr(const T *array, const size_t size) {
    for (size_t i = 0; i <= size-1; i++) {
        std::cout << array[i] << '\n';
    }
}

// Prints contents of an array separated by n number of whitespaces (default 4)
template <typename T>
void printtab_arr(const T *array, const size_t size, const short n=4) {
    for (size_t i = 0; i <= size-1; i++) {
        std::cout << array[i] << std::string(n, ' ');
    }
}

// Checks whether an array has a specified element.
template <typename T>
bool contains(const T *array, const size_t size, const T element) {
    if (size == 0) {
        return false;
    }
    for (size_t i = 0; i <= size-1; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Fills array with a specified value.
template <typename T>
void fill(const T *array, const size_t size, const T value) {
    if (size == 0) {
        return;
    }
    for (size_t i = 0; i <= size-1; i++) {
        array[i] = value;
    }
}

// Fills array with a value if condition is met
template <typename T>
void fill_if(const T *array, const size_t size, const T value, const bool condition) {
    if (size == 0) {
        return;
    }
    for (size_t i = 0; i <= size-1; i++) {
        if (condition == true) {
            array[i] = value;
        }
    }
}

// Reverses the elements of an array
template <typename T>
void reverse(T *array, const size_t size) {
    if (size < 2) {
        return;
    }
    // Divide by 2 here to always stop at the middle element (EX: 5 / 2 = 2)
    for (size_t i = 0; i < size / 2; i++) {
        std::swap(array[i], array[size - i - 1]);
    }
}

// Returns the first index position of a given value, or zero if not found.
template <typename T>
size_t first_index(const T *array, const size_t size, const T value) {
    if (size == 0) {
        return 0;
    }
    for (size_t i = 0; i <= size-1; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return 0;
}

// Returns a vector of all indices of a value.
template <typename T>
std::vector<T> indices(const T *array, const size_t size, const T value) {
    // Reserving memory because array size is known
    std::vector<T> new_vec;
    new_vec.reserve(size);
    if (size == 0) {
        return new_vec;
    }
    for (size_t i = 0; i <= size-1; i++) {
        if (array[i] == value) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns the maximum value in an array.
template <typename T>
T max(const T *array, const size_t size) {
    T maximum = array[0];
    for (size_t i = 1; i <= size-1; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

// Returns the minimum value in an array
template <typename T>
T min(const T *array, const size_t size) {
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
std::vector<T> arr_to_vec(const T *array, const size_t size) {
    // Reserving size because array size is known
    std::vector<T> new_vec;
    new_vec.reserve(size);
    if (size == 0) {
        return new_vec;
    }
    for (size_t i = 0; i <= size-1; i++) {
        new_vec.push_back(array[i]);
    }
    return new_vec;
}

// Zero out a numerical array
template <typename T>
void zero(T *array, const size_t size) {
    for (size_t i = 0; i <= size-1; i++) {
        array[i] = 0;
    }
}

// Checks if two arrays are identical in size, elements, and element order.
template <typename T>
bool is_copy(const T *array_1, const size_t size_1, const T *array_2, const size_t size_2) {
    if (size_1 != size_2) {
        return false;
    }
    if (size_1 == 0 || size_2 == 0) {
        return false;
    }
    for (size_t i = 0; i <= size_1-1; i++) {
        if (array_1[i] != array_2[i]) {
            return false;
        }
    }
    return true;
}

// Sorts a numerical array in descending order (greatest to least)
template <typename T>
void sort_desc(T *array, const size_t size) {
    if (size == 0) {
        return;
    }
    // Minus 2 here so i+1 is within bounds
    for (size_t i = 0; i <= size-2; i++) {
        if (array[i] < array[i+1]) {
            std::swap(array[i], array[i+1]);
            // Decrement by 2 here to effectively decrement by 1 after for loop's increment
            if (i > 0) {
                i -= 2;
            }
        }
    }
}

// Sorts a numerical array in ascending order (least to greatest)
template <typename T>
void sort_asc(T *array, const size_t size) {
    if (size == 0) {
        return;
    }
    // Minus 2 so i+1 is within bounds
    for (size_t i = 0; i <= size-2; i++) {
        if (array[i] > array[i+1]) {
            std::swap(array[i], array[i+1]);
            // Decrement by 2 here to effectively decrement by 1 after for loop's increment
            if (i > 0) {
                i -= 2;
            }
        }
    }
}

// Checks whether a numerical array is sorted in descending order
template <typename T>
bool is_sorted_desc(const T *array, const size_t size) {
    if (size == 0) {
        return false;
    }
    for (size_t i = 0; i <= size-2; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}

// Checks whether a numerical array is sorted in ascending order
template <typename T>
bool is_sorted_asc(const T *array, const size_t size) {
    if (size == 0) {
        return false;
    }
    for (size_t i = 0; i <= size-2; i++) {
        if (array[i] < array[i+1]) {
            return false;
        }
    }
    return true;
}

// Returns number of elements shared in common between two arrays
template <typename T>
int count_matching(const T *array_1, const size_t size_1, const T *array_2, const size_t size_2) {
    int count = 0;
    if (size_1 == 0 || size_2 == 0) {
        return 0;
    }
    // Nested for loop to differentiate between arrays of different sizes and element ordering, while still yielding an accurate count
    for (size_t i = 0; i <= size_1-1; i++) {
        for (size_t j = 0; j <= size_2-1; j++) {
            if (array_1[i] == array_2[j]) {
                count++;
            }
        }
    }
    return count;
}

// Checks whether two arrays of equal size have the same contents in reverse order
template <typename T>
bool is_mirrored(const T *array_1, const size_t size_1, const T *array_2, const size_t size_2) {
    if (size_1 != size_2) {
        return false;
    }
    if (size_1 == 0 || size_2 == 0) {
        return false;
    }
    if (size_1 == 1 || size_2 == 1) {
        if (array_1[0] == array_2[0]) {
            return true;
        }
        return false;
    }
    const size_t bounds = size_1 - 1;
    for (size_t i = 0; i <= bounds; i++) {
        if (array_1[i] != array_2[bounds-i]) {
            return false;
        }
    }
    return true;
}

// Shifts array elements to the right by n number of places (i. e. {1, 2, 3} -> {3, 1, 2})
template <typename T>
void shift_right(T *array, const size_t size, int n=1) {
    if (size == 0) {
        return;
    }
    for (size_t i = size-1; i > 0; i--) {

    }
}

// Copies elements from one array to another of the same size
template <typename T>
void copy(const T *array_1, const size_t size_1, T *array_2, const size_t size_2) {
    if (size_1 != size_2) {
        return;
    }
    if (size_1 == 0 || size_2 == 0) {
        return;
    }
    for (size_t i = 0; i <= size_1-1; i++) {
        array_2[i] = array_1[i];
    }
}

// Returns sum of elements in a numerical array
template <typename T>
T sum_array(const T *array, const size_t size) {
    T sum = 0;
    if (size == 0) {
        return sum;
    }
    for (size_t i = 0; i <= size-1; i++) {
        sum += array[i];
    }
    return sum;
}

// Returns mean of elements in a numerical array
template <typename T>
T avg_array(const T *array, const size_t size) {
    T sum = 0;
    for (size_t i = 0; i <= size-1; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Returns the number of occurrences of an element in an array
template <typename T>
T count_of(const T *array, const size_t size, const T element) {
    T count = 0;
    for (size_t i = 0; i <= size-1; i++) {
        if (array[i] == element) {
            ++count;
        }
    }
    return count;
}

// Sums elements between two index positions, inclusive.
template <typename T>
T sum_between(const T *array, const size_t size, size_t pos_1, size_t pos_2) {
    if (size == 0) {
        return 0;
    }
    if (pos_1 > pos_2) {
        pos_1 = pos_2-1;
    }
    if (pos_2 > size-1) {
        pos_2 = size-1;
    }

    T sum = 0;

    for (size_t i = pos_1; i <= pos_2; i++) {
        sum += array[i];
    }

    return sum;
}

// Averages elements between two index bounds, inclusive.
template <typename T>
T avg_between(const T *array, const size_t size, size_t pos_1, size_t pos_2) {
    if (size == 0) {
        return 0;
    }
    if (pos_1 > pos_2) {
        pos_1 = pos_2-1;
    }
    if (pos_2 > size-1) {
        pos_2 = size-1;
    }
    T sum = 0;
    T range = pos_2 - pos_1;
    for (size_t i = pos_1; i <= pos_2; i++) {
        sum += array[i];
    }
    return sum / range;
}

#endif //HELPERFUNCTIONS_ARRAY_FUNC_H