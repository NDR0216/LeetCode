class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;

            unordered_map<int, int>::iterator found = dict.find(sum);
            if (found == dict.end()) { // not found
                dict[sum] = i;
            } else if (found->second <= i - 2) {
                return true;
            }
        }

        return false;
    }
};
