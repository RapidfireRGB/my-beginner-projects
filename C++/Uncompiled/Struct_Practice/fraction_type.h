#ifndef STRUCTPRACTICE_FRACTION_TYPE_H
#define STRUCTPRACTICE_FRACTION_TYPE_H
#include <iostream>

// Fraction data type which takes two integers to construct (Numerator, Denominator).
// If no Denominator is specified, it will default to value of 1.
struct fraction {
    int numerator;
    int denominator;
    char divisor = '/';

    // Default constructor for initializing a fraction. Value of (1/1).
    fraction() {
        numerator = 1;
        denominator = 1;
    }

    // Constructor with numerator and denominator parameters.
    explicit fraction(const int numerator, int denominator = 1) : numerator(numerator), denominator(denominator) {
    }

    // Destructor.
    ~fraction() = default;

    // Overloading the '=' operator. Returns type fraction (x/1).
    fraction operator=(const int x) const {
        fraction new_frac(x, 1);
        return new_frac;
    }

    // ARITHMETIC OPERATORS
    // Overloading the '+' operator. Returns type fraction.
    fraction operator+(const fraction frac_b) const {
        // If initial fraction's denominator is not equivalent, cross multiply the denominators before adding numerators.
        // Else, simply add the numerators.
        fraction result;
        if (denominator != frac_b.denominator) {
            result.numerator = (numerator * frac_b.denominator) + frac_b.numerator;
            result.denominator = denominator * frac_b.denominator;

            result.validate();
            return result;
        }
        result.numerator = numerator + frac_b.numerator;
        result.denominator = denominator;

        result.validate();
        return result;
    }

    // Overloading the '-' operator. Returns type fraction.
    fraction operator-(const fraction frac_b) const {
        // If the two denominators are not equivalent, cross multiply the denominators before performing subtraction.
        // Else, subtract the numerators.
        fraction result;

        if (denominator != frac_b.denominator) {
            result.numerator = (numerator * frac_b.denominator) - (frac_b.numerator * denominator);
            result.denominator = denominator * frac_b.denominator;

            result.validate();
            return result;
        }

        result.numerator = numerator - frac_b.numerator;
        result.denominator = denominator;

        result.validate();
        return result;
    }

    // Overloading the '*' operator. Returns type fraction.
    fraction operator*(const fraction frac_b) const {
        fraction result;

        result.numerator = numerator * frac_b.numerator;
        result.denominator = denominator * frac_b.denominator;

        result.validate();
        return result;
    }

    //Overloading the '/' operator. Returns type fraction.
    fraction operator/(const fraction frac_b) const {
        fraction result = *this;

        result.numerator = numerator * frac_b.denominator;
        result.denominator = denominator * frac_b.numerator;

        result.validate();
        return result;
    }

    // Overloading the '++' operator to increment numerator only. Type void.
    void operator++() {
        numerator++;
    }

    // Overloading the '--' operator tot decrement numerator only. Type void.
    void operator--() {
        numerator--;
    }

    // COMPARISON OPERATORS
    // Overloading the '==' operator. Returns type bool.
    bool operator==(const fraction frac_b) const {
        fraction new_1 = *this;
        new_1.simplify();

        fraction new_2 = frac_b;
        new_2.simplify();

        if (new_1.denominator != new_2.denominator) {
            new_1.~fraction();
            new_2.~fraction();
            return false;

        }

        if (new_1.denominator == new_2.denominator && new_1.numerator == new_2.numerator) {
            new_1.~fraction();
            new_2.~fraction();
            return true;
        }

        if (new_1.denominator == new_2.denominator && new_1.numerator != new_2.numerator) {
            new_1.~fraction();
            new_2.~fraction();
            return false;
        }

        new_1.~fraction();
        new_2.~fraction();
        return false;
    }

    // Overloading '!=' Operator. Returns type bool.
    bool operator!=(const fraction frac_b) const {
        fraction new_1 = *this;
        new_1.simplify();

        fraction new_2 = frac_b;
        new_2.simplify();

        if (new_1.denominator != new_2.denominator) {
            new_1.~fraction();
            new_2.~fraction();
            return false;
        }

        if (new_1.denominator == new_2.denominator && new_1.numerator != new_2.numerator) {
            new_1.~fraction();
            new_2.~fraction();
            return true;
        }

        if (new_1.denominator == new_2.denominator && new_1.numerator == new_2.numerator) {
            new_1.~fraction();
            new_2.~fraction();
            return false;
        }

        new_1.~fraction();
        new_2.~fraction();
        return false;
    }

    // Basic print method with 1 whitespace at the end. Type void.
    void print() const {
        std::cout << numerator << divisor << denominator << " ";
    }

    // Compares base fraction against fraction parameter and returns the greatest of the two.
    // Accepts type fraction; Returns type fraction.
    [[nodiscard]] fraction greater(const fraction fract_b) const {
        fraction fract_a(numerator, denominator);
        const fraction new_1(numerator * fract_b.denominator, denominator * fract_b.denominator);
        const fraction new_2(fract_b.numerator * denominator, fract_b.denominator * denominator);

        if (new_1.numerator > new_2.numerator) {
            new_1.~fraction();
            new_2.~fraction();

            validate();
            return fract_a;
        }
        new_1.~fraction();
        new_2.~fraction();

        validate();
        return fract_b;
    }

    // Simplifies a fraction if both its numerator and denominator are divisible by digits between (2-10). Type void.
    void simplify() {
        for (int i = 2; i <= 10; i++) {
            if (denominator % i == 0 && numerator % i == 0) {
                numerator /= i;
                denominator /= i;

                if (denominator % i == 0 && numerator % i == 0) {
                    simplify();
                } else {
                    break;
                }
            }
        }
    }

    // Transforms a fraction to its inverse. Type void.
    void invert() {
        const int new_numerator = denominator;
        const int new_denominator = numerator;

        numerator = new_numerator;
        denominator = new_denominator;
        validate();
    }

    // Manual Multiplication method. Accepts specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void multiply(const int numerator_b, const int denominator_b = 1) {
        numerator *= numerator_b;
        denominator *= denominator_b;
        validate();
    }

    // Manual Multiplication method that simplifies if possible. Takes specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void simmult(const int numerator_b, const int denominator_b=1) {
        numerator *= numerator_b;
        denominator *= denominator_b;

        simplify();
        validate();
    }

    // Manual Division method. Accepts specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void divide(const int numerator_b, const int denominator_b = 1) {
        numerator *= denominator_b;
        denominator *= numerator_b;
        validate();
    }

    // Manual Division method that simplifies if possible. Takes specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void simdiv(const int numerator_b, const int denominator_b = 1) {
        numerator *= denominator_b;
        denominator *= numerator_b;
        validate();
    }

    // Manual Addition method. Accepts specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void add(const int numerator_b, const int denominator_b = 1) {
        fraction new_1(numerator * denominator_b, denominator * denominator_b);
        const fraction new_2(numerator_b * denominator, denominator_b * denominator);

        new_1.numerator += new_2.numerator;
        new_1.denominator += new_2.denominator;
        new_2.~fraction();

        numerator = new_1.numerator;
        denominator = new_1.denominator;
        new_1.~fraction();

        validate();
    }

    // Manual Addition method that simplifies if possible. Takes specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void simadd(const int numerator_b, const int denominator_b = 1) {

        fraction new_1(numerator * denominator_b, denominator * denominator_b);
        const fraction new_2(numerator_b * denominator, denominator_b * denominator);

        new_1.numerator += new_2.numerator;
        new_1.denominator += new_2.denominator;
        new_2.~fraction();

        new_1.simplify();

        numerator = new_1.numerator;
        denominator = new_1.denominator;
        new_1.~fraction();

        validate();
    }

    // Manual Subtraction method. Accepts specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void subtract(const int numerator_b, const int denominator_b = 1) {
        fraction new_1(numerator * denominator_b, denominator * denominator_b);
        const fraction new_2(numerator_b * denominator, denominator_b * denominator);

        new_1.numerator -= new_2.numerator;
        new_1.denominator -= new_2.denominator;
        new_2.~fraction();

        numerator = new_1.numerator;
        denominator = new_1.denominator;
        new_1.~fraction();

        validate();
    }

    // Manual Subtraction method that simplifies if possible. Takes specified int numerator and int denominator.
    // If a denominator is not specified, defaults to a value of 1. Type void.
    void simsub(const int numerator_b, const int denominator_b = 1) {
        fraction new_1(numerator * denominator_b, denominator * denominator_b);
        fraction new_2(numerator_b * denominator, denominator_b * denominator);

        new_1.numerator -= new_2.numerator;
        new_1.denominator -= new_2.denominator;
        new_2.~fraction();

        numerator = new_1.numerator;
        denominator = new_1.denominator;
        new_1.~fraction();

        simplify();
        validate();
    }

    // Transforms a fraction to its decimal value representation. Returns type double. Type void.
    [[nodiscard]] double fractodec() const {
        validate();
        const double a = numerator;
        const double b = denominator;
        return a/b;
    }

    // Helper function to check if a denominator is zero at any point. Type void.
    void validate() const {
        if (denominator == 0) {
            std::cerr << "Denominator must be a non-zero value.\n";
        }
    }

};

#endif //STRUCTPRACTICE_FRACTION_TYPE_H