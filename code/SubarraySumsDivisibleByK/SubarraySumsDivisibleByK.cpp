class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = 1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) {
                sum += k;
            }

            dict[sum]++;
        }

        int cnt = 0;
        for (unordered_map<int, int>::iterator it = dict.begin();
             it != dict.end(); ++it) {
            int value = it->second;

            cnt += value * (value - 1) / 2;
        }

        return cnt;
    }
};
