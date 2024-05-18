class Solution {
public:
    int tribonacci(int n) {
        int t[3] = {0, 1, 1};

        for (int i = 3; i <= n; i++) {
            t[i % 3] = t[(i - 1) % 3] + t[(i - 2) % 3] + t[(i - 3) % 3];
        }

        return t[n % 3];
    }
};
