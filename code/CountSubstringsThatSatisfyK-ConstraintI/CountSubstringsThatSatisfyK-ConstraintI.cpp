class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int sum = 0;

        int zeros = 0;
        int ones = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '0') {
                zeros++;
            } else {
                ones++;
            }

            while (left < s.size() && (zeros > k && ones > k)) {
                if (s[left] == '0') {
                    zeros--;
                } else {
                    ones--;
                }

                left++;
            }

            sum += right - left + 1;
        }

        return sum;
    }
};
