class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int idx = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != nums.size()-1 && nums[i] == nums[i + 1]) {
                    nums[idx] = nums[i]*2;
                    idx++;
                    i += 1;
                } else {
                    nums[idx] = nums[i];
                    idx++;
                }                
            }
        }
        for (int i = idx; i < nums.size(); i++) {
            nums[i] = 0;
        }
        
        return nums;
    }
};
