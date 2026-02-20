#include <iostream>
#include <vector>
using namespace std;

// Normal sieve to find primes till sqrt(R)
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

// Segmented Sieve
void segmentedSieve(int L, int R) {

    int limit = sqrt(R);
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    for (int p : primes) {

        int start = max(p * p, ((L + p - 1) / p) * p);

        for (int j = start; j <= R; j += p)
            isPrime[j - L] = false;
    }

    for (int i = 0; i <= R - L; i++) {
        if (isPrime[i] && (i + L) > 1)
            cout << i + L << " ";
    }
}

int main() {
    int L, R;
    cin >> L >> R;
    segmentedSieve(L, R);
}


/*
The segmented sieve is an efficient algorithm to find all prime numbers in a given range [L, R].

STEPS
Pehle √R tak ke primes nikal lo (normal sieve se)
Fir L se R tak ek array banao
√R tak ke har prime ka multiple L-R range me mark karo
Jo numbers unmarked bache → wahi primes hain

Segmented Sieve is used when we need primes in a specific range [L, R] and R is very large.
First, we find primes up to √R using normal sieve.
Then we mark multiples of those primes in the range [L, R].
This reduces memory usage and works efficiently for large ranges.

LOGIC
√R primes nikaalo
Range me multiples mark karo

Time Complexity: O(n log log n) for finding primes up to √R + O((R-L+1) log log R) for marking multiples.
Space Complexity: O(√R) for storing primes + O(R-L+1) for the range array.
*/