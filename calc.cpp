#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "Calc input: ";
    string expr;
    getline(cin, expr);

    // Деление на числа и знаки
    vector<double> numbers;
    vector<char> operations;
    string num_str;
    
    for (char c : expr) {
        if (isdigit(c) || c == '.') {
            num_str += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!num_str.empty()) {
                numbers.push_back(stod(num_str));
                num_str.clear();
            }
            operations.push_back(c);
        }
    }
    if (!num_str.empty()) {
        numbers.push_back(stod(num_str));
    }

    // Умножение/деление
    for (size_t i = 0; i < operations.size(); ) {
        if (operations[i] == '*' || operations[i] == '/') {
            double a = numbers[i];
            double b = numbers[i+1];
            double result = (operations[i] == '*') ? a * b : a / b;
            
            numbers[i] = result;
            numbers.erase(numbers.begin() + i + 1);
            operations.erase(operations.begin() + i);
        } else {
            i++;
        }
    }

    // Сложение/вычитание
    double total = numbers[0];
    for (size_t i = 0; i < operations.size(); i++) {
        if (operations[i] == '+') {
            total += numbers[i+1];
        } else {
            total -= numbers[i+1];
        }
    }

    cout << "Calc output: " << total << endl;
    return 0;
}
