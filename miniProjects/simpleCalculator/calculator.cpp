#include <iostream>
#include <cmath>

using namespace std;
int main();

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

double exponent(double a, double b) {
    return pow(a, b);
}

int main() {
    while (true) {
        double num_1;
        cout << "You can enter two numbers. Type your first number: ";
        cin >> num_1;

        double num_2;
        cout << "Type your second number: ";
        cin >> num_2;

        string operation;
        cout << "Which operation do you want to do (Add, Subtract, Multiply, Divide, Exponent): ";
        cin >> operation;

        if (operation == "Add" || operation == "add") {
            cout << add(num_1, num_2) << endl;
        }
        else if (operation == "Subtract" || operation == "subtract") {
            cout << subtract(num_1, num_2) << endl;
        }
        else if (operation == "Multiply" || operation == "multiply") {
            cout << multiply(num_1, num_2) << endl;
        }
        else if (operation == "Divide" || operation == "divide") {
            cout << divide(num_1, num_2) << endl;
        }
        else if (operation == "Exponent" || operation == "exponent") {
            cout << exponent(num_1, num_2) << endl;
        }
        else {
            cout << "Invalid operation." << endl;
            continue;
        }
        break;
    }
    return 0;
}