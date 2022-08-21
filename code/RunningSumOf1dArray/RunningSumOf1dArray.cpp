class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum (nums.size());
        
        for (int i = 0 ; i < nums.size(); i++) {
            if (i > 0) {
                sum[i] = sum[i-1] + nums[i];
            } else {
                sum[i] = nums[i];
            }
        }
        
        return sum;
    }
};
