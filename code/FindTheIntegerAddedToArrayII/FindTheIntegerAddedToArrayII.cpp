class Solution {
public:
    bool check(const unordered_map<int, int>& freq1,
               const unordered_map<int, int>& freq2, int x) {
        for (unordered_map<int, int>::const_iterator it = freq2.begin();
             it != freq2.end(); ++it) {
            int key = it->first;
            int value = it->second;

            unordered_map<int, int>::const_iterator found =
                freq1.find(key - x); // nums1 + x = nums2

            if (found == freq1.end() || found->second < value) {
                return false;
            }
        }

        return true;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        partial_sort(nums1.begin(), nums1.begin() + 3, nums1.end());
        int min2 = INT_MAX;
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;

        for (int i = 0; i < nums1.size(); i++) {
            freq1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            min2 = min(min2, nums2[i]);
            freq2[nums2[i]]++;
        }

        for (int i = 2; i >= 0; i--) {
            if (check(freq1, freq2, min2 - nums1[i])) {
                return min2 - nums1[i];
            }
        }

        return 0;
    }
};
