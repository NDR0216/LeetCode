class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = 1;
        int min = nums[0];
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] > min+k) {
                min = nums[i];
                n++;
            }
        }
        
        return n;
    }
};
