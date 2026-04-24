class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }

        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> dict;

        int min_dist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator found = dict.find(nums[i]);

            if (found != dict.end()) {
                min_dist = min(min_dist, i - found->second);
            }

            dict[reverse(nums[i])] = i;
        }

        if (min_dist == INT_MAX) {
            return -1;
        }
        return min_dist;
    }
};
