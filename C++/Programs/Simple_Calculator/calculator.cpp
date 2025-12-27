#include <iostream>
#include <cmath>


double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double divide(double a, double b) {
    return a / b;
}

double multiply(double a, double b) {
    return a * b;
}

long long exponent(double a, double b) {
    long long result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

double inverse(double n) {
    return 1 / n;
}

double percent_change(double a, double b) {
    return (a-b)/a;
}

double absval(double n) {
    if (n >= 0.0) {
        return n;
    } else if (n < 0.0) {
        return n * -1.0;
    } else {
        std::cerr << "Invalid input.\n";
        return -1;
    }
}

long long factorial(int n) {
    long long result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}

int main() {
    while (true) {

        std::string operation;
        std::cout << "Which operation do you want to do (Add, Subtract, Multiply, Divide, Exponent, Inverse):\n";
        std::cin >> operation;

        double num_1;
        std::cout << "Enter your first number:\n";
        std::cin >> num_1;

        if (num_1 >= exponent(2, 63)-1) {
            std::cerr << "Your number is too big!\n";
            break;
        }

        double num_2;
        std::cout << "Enter your second number:\n";
        std::cin >> num_2;

        if (num_2 >= exponent(2, 63)-1) {
            std::cerr << "Your number is too big!\n";
            break;
        }

        if (operation == "Add" || operation == "add") {
            std::cout << add(num_1, num_2) << "\n";
        }

        else if (operation == "Subtract" || operation == "subtract") {
            std::cout << subtract(num_1, num_2) << "\n";
        }

        else if (operation == "Multiply" || operation == "multiply") {
            std::cout << multiply(num_1, num_2) << "\n";
        }

        else if (operation == "Divide" || operation == "divide") {
            std::cout << divide(num_1, num_2) << "\n";
        }

        else if (operation == "Exponent" || operation == "exponent") {
            std::cout << exponent(num_1, num_2) << "\n";
        }

        else if (operation == "Inverse" || operation == "inverse") {
            std::cout << inverse(num_1) << "\n";
        }

        else {
            std::cerr << "Invalid operation.\n";
            break;
        }

        char response;
        std::cout << "Do you want to continue? (y/n)\n";
        std::cin >> response;
        if (response == 'y') {
            continue;
        }

        break;
    }
    return 0;
}