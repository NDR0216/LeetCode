class Solution {
public:
    bool* SieveOfEratosthenes(int n) { // find prime[2:n-1]
        bool* prime = new bool[n];
        fill(prime, prime + n, true);

        for (int i = 2; i < sqrt(n); i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    int countPrimes(int n) {
        bool* prime = SieveOfEratosthenes(n);

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }

        return count;
    }
};
