class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        unsigned int upper_bound = 1; // [1, upper_bound)

        int patches = 0;

        int idx = 0;
        while (upper_bound <= n) {
            if (idx < nums.size() && nums[idx] <= upper_bound) {
                upper_bound += nums[idx];

                idx++;
            } else {
                // add upper_bound
                upper_bound *= 2;
                patches++;
            }
        }

        return patches;
    }
};
