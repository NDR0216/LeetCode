class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;

            if (dict.find(sum) != dict.end()) {
                if (dict[sum] <= i - 2) {
                    return true;
                }
            } else {
                dict[sum] = i;
            }
        }

        return false;
    }
};
