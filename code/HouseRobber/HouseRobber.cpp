class Solution {
public:
    int rob(vector<int>& nums) {
        // rob(n) = max(rob(n-2)+nums[n], rob(n-1))
        int max_1 = 0; // rob(n-1)
        int max_2 = 0; // rob(n-2)

        for (int i = 0; i < nums.size(); i++) {
            int temp = max(max_2 + nums[i], max_1);

            max_2 = max_1;
            max_1 = temp;
        }

        return max_1;
    }
};
