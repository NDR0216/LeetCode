class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_length = 1;
        int inc = 1;
        int dec = 1;

        int length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                inc = 1;
                dec++;
            } else {
                inc = 1;
                dec = 1;
            }

            max_length = max(max_length, max(inc, dec));
        }

        return max_length;
    }
};
