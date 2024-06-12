class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int i = 0;
        while (i <= right) {
            switch (nums[i]) {
            case 0:
                swap(nums[left], nums[i]);
                left++;
                i++;
                break;
            case 1:
                i++;
                break;
            case 2:
                swap(nums[right], nums[i]);
                right--;
                break;
            }
        }
    }
};
