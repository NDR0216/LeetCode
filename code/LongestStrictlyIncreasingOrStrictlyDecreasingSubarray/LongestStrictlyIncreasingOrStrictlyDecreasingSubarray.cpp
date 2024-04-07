class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max = 1;

        int length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                length++;
            } else {
                if (length > max) {
                    max = length;
                }
                length = 1;
            }
        }
        if (length > max) {
            max = length;
        }

        length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                length++;
            } else {
                if (length > max) {
                    max = length;
                }
                length = 1;
            }
        }
        if (length > max) {
            max = length;
        }

        return max;
    }
};
