class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long> presum(nums.size());
        map<int, int> dict;
        
        presum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            presum[i] = presum[i-1] + (long long) nums[i];
        }
        
        long long max = 0;
        int length = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (length < k) {
                if (dict[nums[i]] > 0) {
                    map<int, int> temp;
                    dict = temp;
                    length = 0;
                    i = i-1;
                } else {
                    dict[nums[i]] = 1;
                    length++;
                }
            } else {
                dict[nums[i-k]] = 0;
                
                if (dict[nums[i]] > 0) {
                    map<int, int> temp;
                    dict = temp;
                    length = 0;
                } else {
                    dict[nums[i]] = 1;
                }
            }

            if (length == k) {
                if (i-k < 0 && max < presum[i]) {
                    max = presum[i];
                } else if (max < presum[i]-presum[i-k]) {
                    max = presum[i]-presum[i-k];
                }
            }
        }
        
        return max;  
    }
};
