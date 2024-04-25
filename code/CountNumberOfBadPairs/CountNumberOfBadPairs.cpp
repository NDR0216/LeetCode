class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long pairs = 0; 
        
        map<int, int> dict;
        for (int i = nums.size()-1; i >= 0; i--) {
            nums[i] -= i;
            
            if (dict.count(nums[i]) > 0) {
                dict[nums[i]] += 1;
            } else {
                dict[nums[i]] = 1;
            }
            
            pairs += long(nums.size()-i-dict[nums[i]]);
        }
        
        return pairs;
    }
};
