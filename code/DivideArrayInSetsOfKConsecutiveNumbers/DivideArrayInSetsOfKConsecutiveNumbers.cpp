class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            
            while (freq[start - 1] != 0) {
                start--;
            }

            while (start <= nums[i]) {
                int count = freq[start];

                if (count != 0) {
                    for (int i = 0; i < k; i++) {
                        if (freq[start + i] < count) {
                            return false;
                        }

                        freq[start + i] -= count;
                    }
                }

                start++;
            }
        }

        return true;
    }
};
