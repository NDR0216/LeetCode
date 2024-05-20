class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            k ^= nums[i];
        }

        return popcount((unsigned int)k);
    }
};
