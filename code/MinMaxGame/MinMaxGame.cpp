class Solution {
public:    
    int minMaxGame(vector<int>& nums) {
        int size = nums.size();
        while (size != 1) {
            size /= 2;
            for (int i = 0; i < size; i++) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
        }
        return nums[0];
    }
};
