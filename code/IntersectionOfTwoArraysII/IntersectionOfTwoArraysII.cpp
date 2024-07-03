class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }

        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            auto found = freq.find(nums2[i]);

            if (found != freq.end() && found->second > 0) {
                found->second--;
                result.push_back(nums2[i]);
            }
        }

        return result;
    }
};
