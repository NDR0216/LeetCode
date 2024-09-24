class Solution {
private:
    const int NUM_MAX = 101;

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

    int maximumPrimeDifference(vector<int>& nums) {
        bool* prime = SieveOfEratosthenes(NUM_MAX);
        prime[0] = false;
        prime[1] = false;

        int idx_first, idx_last;

        for (idx_first = 0; idx_first < nums.size(); idx_first++) {
            if (prime[nums[idx_first]]) {
                break;
            }
        }

        for (idx_last = nums.size() - 1; idx_last >= 0; idx_last--) {
            if (prime[nums[idx_last]]) {
                break;
            }
        }

        return idx_last - idx_first;
    }
};
