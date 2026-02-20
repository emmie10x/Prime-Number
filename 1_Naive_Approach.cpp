#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}

/*
In the naive approach, I check divisibility of n from 2 to n-1.
If any number divides n, then it is not prime.
In the worst case, if n is prime, the loop runs n-2 times,
so time complexity becomes O(n).
*/