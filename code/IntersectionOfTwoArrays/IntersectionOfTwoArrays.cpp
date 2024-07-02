class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uniq(nums1.begin(), nums1.end());

        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (uniq.erase(nums2[i])) {
                result.push_back(nums2[i]);
            }
        }

        return result;
    }
};
