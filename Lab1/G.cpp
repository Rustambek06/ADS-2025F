#include <iostream>
#include <cmath>

bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    int limit = static_cast<int>(std::sqrt(x));
    for (int i = 3; i <= limit; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    int superprimes[n + 1];

    int count_primes = 0;
    int count_superprimes = 0;
    int num = 1;

    while (count_superprimes < n + 1) {
        num++;
        if (is_prime(num)) {
            count_primes++;
            if (is_prime(count_primes)) {
                superprimes[count_superprimes] = num;
                count_superprimes++;
            }
        }
    }

    std::cout << superprimes[n - 1];
    return 0;
}