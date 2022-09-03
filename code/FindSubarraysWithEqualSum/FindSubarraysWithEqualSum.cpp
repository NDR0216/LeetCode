class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int, int> dict;
        
        for (int i = 0; i < nums.size()-1; i++) {
            if (dict.count(nums[i]+nums[i+1]) > 0) {
                if (dict[nums[i]+nums[i+1]] == 1) {
                    return true;
                }
            } else {
                dict[nums[i]+nums[i+1]] = 1;
            }
        }
        
        return false;
    }
};
