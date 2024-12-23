#include <iostream>
using namespace std;

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case: F(0) = 0
    } else if (n == 1) {
        return 1; // Base case: F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Validate input
    if (n < 0 || n > 30) {
        cout << "Invalid input. Please enter a value between 0 and 30.\n";
        return 0;
    }

    int result = fibonacci(n);
    cout << "F(" << n << ") = " << result << endl;

    return 0;
}
