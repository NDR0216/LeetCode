class Solution {
public:
    string largestPalindrome(int n, int k) {
        int* rem = new int[n]; // rem[i] = 10^i % k

        rem[0] = 1 % k;
        for (int i = 1; i < n; i++) {
            rem[i] = 10 * rem[i - 1] % k;
        }

        // dp[i][j]: most significant digit of (2i+1 or 2i+2)-length int which %
        // k = j; -1 means unreachable
        int** dp = new int*[(n + 1) / 2];
        for (int i = 0; i < (n + 1) / 2; i++) {
            dp[i] = new int[k]();
            fill(dp[i], dp[i] + k, -1);
        }

        // start at middle, (n-1)/2'th digit
        for (int i = 0; i < (n + 1) / 2; i++) {
            // add idx'th and n-1-idx'th digit
            int idx = (n - 1) / 2 - i;

            int rem_base = rem[idx]; // 10^idx % k + 10^(n-1-idx) % k
            if (idx != n - 1 - idx) {
                rem_base += rem[n - 1 - idx];
            }

            for (int j = 9; j >= 0; j--) {
                if (i == 0) {
                    int new_k = (j * rem_base) % k;

                    dp[i][new_k] = max(dp[i][new_k], j);

                    continue;
                }

                for (int kk = 0; kk < k; kk++) {
                    if (dp[i - 1][kk] != -1) {
                        int new_k = (kk + j * rem_base) % k;

                        dp[i][new_k] = max(dp[i][new_k], j);
                    }
                }
            }
        }

        string palindrome(n, ' ');

        // trace back
        int next_k = 0;
        for (int i = (n - 1) / 2; i >= 0; i--) {
            // add idx'th and n-1-idx'th digit
            int idx = (n - 1) / 2 - i;

            int rem_base = rem[idx]; // 10^idx % k + 10^(n-1-idx) % k
            if (idx != n - 1 - idx) {
                rem_base += rem[n - 1 - idx];
            }

            palindrome[idx] = ('0' + dp[i][next_k]);
            palindrome[n - 1 - idx] = ('0' + dp[i][next_k]);

            next_k = (next_k - dp[i][next_k] * rem_base) % k;
            if (next_k < 0) {
                next_k += k;
            }
        }

        return palindrome;
    }
};
