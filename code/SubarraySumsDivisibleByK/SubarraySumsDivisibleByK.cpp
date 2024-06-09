class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = 1;

        int cnt = 0;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) {
                sum += k;
            }

            cnt += dict[sum];
            dict[sum]++;
        }

        return cnt;
    }
};
