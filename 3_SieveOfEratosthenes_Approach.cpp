#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    sieve(n);

    return 0;
}


/*
Instead of checking each number individually,
I create a boolean array from 0 to n and initially mark all numbers as prime.
Then starting from 2, if a number is still marked as prime,
I mark all its multiples as non-prime.
Finally, the numbers that remain marked true are prime."

Step-by-Step Simple
Ek array bana li size n+1
Sabko true mark kar diya
0 aur 1 ko false kar diya
2 se √n tak loop chala
Agar number prime hai → uske multiples false kar diye
End me jo true bache → wahi prime numbers

For checking a single number, √n approach is better.
But if we need all primes till n, Sieve is more efficient.

Sieve of Eratosthenes is an optimized algorithm to find all primes up to n.
It works by marking multiples of each prime number as non-prime.
It runs in O(n log log n) time and uses O(n) space.
*/