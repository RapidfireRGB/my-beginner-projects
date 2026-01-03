#ifndef STRUCTPRACTICE_BLOCK_TYPE_H
#define STRUCTPRACTICE_BLOCK_TYPE_H
#include <iostream>

// Stores up to 4 integers at a time. TODO add comparison operators.
struct block {
    int a;
    int b;
    int c;
    int d;

    // Default initialization
    block() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }

    // Block constructor with parameters. Accepts 4 integer values.
    block(const int a, const int b, const int c, const int d) : a(a), b(b), c(c), d(d) {
    }

    ~block() = default;



    // Helper function to keep zeros at the top, and real values at the bottom. Type void. TODO finish & find a better method
    void validate() {
        block temp = *this;
        if (a == 0 && b == 0 && c == 0 && d != 0) {
            a = temp.d;
            d = 0;
        }
        if (a == 0 && b == 0 && c != 0 && d != 0) {

        }
        if (a != 0 && b == 0 && c != 0) {
            b = temp.c;
            c = 0;
        }
        if (a != 0 && b != 0 && c == 0 && d != 0) {
            c = temp.d;
            d = 0;
        }

    }

    // Overloading [] to allow indexing.
    int operator[](const int index) const {
        if (index < 0 || index > 3) {
            std::cerr << "Index out of range\n";
        }
        if (index == 0) {
            return a;
        }
        if (index == 1) {
            return b;
        }
        if (index == 2) {
            return c;
        }
        if (index == 3) {
            return d;
        }
        return 0;
    }

    // Inserts an integer in place of the first 0 found.
    void append(const int n) {
        if (a == 0) {
            a = n;
        } else if (b == 0) {
            b = n;
        } else if (c == 0) {
            c = n;
        } else if (d == 0) {
            d = n;
        }
    }

    // Removes an integer from specified position TODO fix default case always triggering.
    void remove(const int index) {
        if (index < 0 || index > 3) {
            std::cerr << "Index out of range\n";
        }
        switch (index) {
            case 0:
                a = 0;
            case 1:
                b = 0;
            case 2:
                c = 0;
            case 3:
                d = 0;
            default:
                std::cerr << "Failed to remove integer from type block\n";
                break;
        }
    }

    // Reverses the order of integers. Type void.
    void reverse() {
        block temp = *this;
        d = temp.a;
        c = temp.b;
        b = temp.c;
        a = temp.d;
        temp.~block();
    }

    // Shifts each integer up by one position. Type void.
    void shiftdown() {
        block temp = *this;
        a = temp.b;
        b = temp.c;
        c = temp.d;
        d = temp.a;
        temp.~block();
    }

    // Shifts each integer down by one position. Type void.
    void shiftup() {
        block temp = *this;
        a = temp.d;
        b = temp.a;
        c = temp.b;
        d = temp.c;
        temp.~block();
    }

    // Swaps the positions of inner and outer integers. Type void.
    void transpose() {
        block temp = *this;
        a = temp.b;
        b = temp.a;
        c = temp.d;
        d = temp.c;
        temp.~block();
    }

    // Sorts elements from greatest to least. TODO test & fix
    void sortgtol() {
        // Create a copy
        const block temp = *this;
        // Check for greatest value, set a equal to it
        if (b > temp.a && b > temp.c && b > temp.d) {
            a = b;
            b = temp.a;
        } else if (c > temp.a && c > temp.b && c > temp.d) {
            a = c;
            c = temp.a;
        } else if (d > temp.a && d > temp.b && d > temp.c) {
            a = d;
            d = temp.a;
        }
        // Check for next greatest value, set b equal to it
        if (c > temp.b && c > temp.d) {
            b = c;
            c = temp.b;
        } else if (d > temp.b && d > temp.c) {
            b = d;
            d = temp.b;
        }
        // Check for next greatest value, set c equal to it and d equal to the lowest value of the two remaining.
        if (c > temp.d) {
            c = temp.c;
            d = temp.d;
        } else if (c < temp.d) {
            c = temp.d;
            d = temp.c;
        }
        // Call destructor here.
        //temp.~block();

    }

    // Sorts elements from least to greatest. TODO finish & test
    //void sortltog() {

    //}

    // Checks if a block is empty. Returns type bool.
    [[nodiscard]] bool empty() const {
        if (a == 0) {
            return true;
        }
        if (b == 0) {
            return true;
        }
        if (c == 0) {
            return true;
        }
        if (d == 0) {
            return true;
        }
        return false;
    }

    // Print contents of block to console. Type void.
    void contents() const {
        switch (this->quantity()) {
            case 0:
                std::cout << '(' << ')';
            case 1:
                std::cout << '(' << a << ')';
            case 2:
                std::cout << '(' << a << ", " << b << ')';
            case 3:
                std::cout << '(' << a << ", " << b << ", " << c << ')';
            default:
                std::cout << '(' << a << ", " << b << ", " << c << ", " << d << ')';
        }

    }

    // Checks the number of elements in a block. Returns type int. TODO fix: if a and d have values, but b and c do not, returns 0.
    [[nodiscard]] int quantity() const {
        if (a != 0 && b != 0 && c != 0 && d != 0) {
            return 4;
        }
        if (a == 0 && b == 0 && c == 0 && d == 0) {
            return 0;
        }
        if (b == 0 && c == 0 && d == 0) {
            return 1;
        }
        if (c == 0 && d == 0) {
            return 2;
        }
        if (d == 0) {
            return 3;
        }
        return 0;
    }

    // Returns the first element.
    [[nodiscard]] int front() const {
        return a;
    }

    // Returns the last element.
    [[nodiscard]] int back() const {
        return d;
    }

    // Accepts type int. Sets all integers within a block equal to a specified value. Type void.
    void fill(const int n) {
        a = n;
        b = n;
        c = n;
        d = n;
    }

    // Sets all elements equal to zero. Type void.
    void zero() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }

    // Swap the contents of two blocks. Type void. TODO fix: does not affect block other. Type void.
    void swap(block other) {
        block temp = *this;
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;

        other.a = temp.a;
        other.b = temp.b;
        other.c = temp.c;
        other.d = temp.d;
        temp.~block();

    }

    // Calculates sum of values within block. Returns type int.
    [[nodiscard]] int sum() const {
        switch (this->quantity()) {
            case 0:
                return 0;
            case 1:
                return a;
            case 2:
                return a + b;
            case 3:
                return a + b + c;
            case 4:
                return a + b + c + d;
            default:
                return 0;
        }
    }

    // Calculates average of values within block. Returns type int.
    // TODO fix: if b is 0, but values exist for all other ints, gets stuck in a loop and does not calculate.
    // TODO fix: does not check for even divisibility and does not account for remainders.
    [[nodiscard]] int mean() const {
        return this->sum() / this->quantity();
    }

    // Returns greatest integer within a block. Returns type int. TODO fix: if b/c are zero, but a/d have values, returns 0.
    [[nodiscard]] int max() const {
        switch (this->quantity()) {
            case 0:
                return 0;
            case 1:
                return a;

            case 2:
                if (a > b) {
                    return a;
                } else {
                    return b;
                }

            case 3:
                if (a > b && a > c) {
                    return a;
                } else if (b > a && b > c) {
                    return b;
                } else if (c > a && c > b) {
                    return c;
                } else {
                    return a;
                }

            case 4:
                if (a > b && a > c && a > d) {
                    return a;
                } else if (b > a && b > c && b > d) {
                    return b;
                } else if (c > a && c > b && c > d) {
                    return c;
                } else if (d > a && d > b && d > c) {
                    return d;
                } else {
                    return a;
                }

            default:
                return 0;
        }
    }

    // Returns lowest value within a block. Returns type int. TODO fix: if b/c are zero, but a/d have values, returns 0.
    [[nodiscard]] int min() const {
        switch (this->quantity()) {
            case 0:
                return 0;
            case 1:
                return a;

            case 2:
                if (a < b) {
                    return a;
                } else {
                    return b;
                }

            case 3:
                if (a < b && a < c) {
                    return a;
                } else if (b < a && b < c) {
                    return b;
                } else if (c < a && c < b) {
                    return c;
                } else {
                    return a;
                }

            case 4:
                if (a < b && a < c && a < d) {
                    return a;
                } else if (b < a && b < c && b < d) {
                    return b;
                } else if (c < a && c < b && c < d) {
                    return c;
                } else if (d < a && d < b && d < c) {
                    return d;
                } else {
                    return a;
                }

            default:
                return 0;
        }
    }

};

#endif //STRUCTPRACTICE_BLOCK_TYPE_H