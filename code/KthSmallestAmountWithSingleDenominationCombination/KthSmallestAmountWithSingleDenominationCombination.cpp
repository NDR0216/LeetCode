class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int max_coin = 0;
        for (int i = 0; i < coins.size(); i++) {
            max_coin = max(max_coin, coins[i]);
        }

        long long* LCMs = new long long[1 << coins.size()];
        for (unsigned int i = 1; i < 1 << coins.size(); i++) {
            LCMs[i] = 1;
            for (int j = 0; j < coins.size(); j++) {
                if ((i >> j) & 1) { // the j'th bit of i
                    LCMs[i] = lcm(LCMs[i], coins[j]);
                }
            }
        }

        // binary search
        long long left = 0, right = (long long)max_coin * k;
        while (left < right) {
            long long mid = left + (right - left) / 2;

            long long count = 0;
            for (unsigned int i = 1; i < 1 << coins.size(); i++) {
                if (popcount(i) % 2) {
                    count += mid / LCMs[i];
                } else {
                    count -= mid / LCMs[i];
                }
            }

            if (count == k) { // count <= mid < count+1
                right = mid;
            } else if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // left == right == k, 1 element

        return left;
    }
};
