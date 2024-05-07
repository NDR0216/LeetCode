class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp; // dp[i]: the last number for length i+1 subsequence

        // maintain dp[i]
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it =
                lower_bound(dp.begin(), dp.end(), nums[i]); // *it >= nums[i]

            if (it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }

        return dp.size();
    }
};
