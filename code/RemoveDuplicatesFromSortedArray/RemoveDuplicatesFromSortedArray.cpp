class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int num = -101;

        for (int i = 0; i < nums.size(); i++) {
            if (num != nums[i]) {
                num = nums[i];
                nums[idx] = num;
                idx++;
            }
        }
        return idx;
    }
};
