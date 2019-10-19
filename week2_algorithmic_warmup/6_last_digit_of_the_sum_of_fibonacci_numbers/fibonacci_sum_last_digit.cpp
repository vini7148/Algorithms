#include <iostream>

int fibonacci_sum_naive(unsigned long long int n) {
    if (n <= 1)
        return n;

    unsigned long long int previous = 0;
    unsigned long long int current  = 1;
    unsigned long long int sum      = 1;

    for (unsigned long long int i = 0; i < n - 1; ++i) {
        unsigned long long int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    unsigned long long int n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
