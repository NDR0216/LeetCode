class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // nums[i] is -1 if [i, i+k-1] is flipped

        // whether nums[i] is flipped or not, aka sum(nums[i-k+1, i] == -1)
        bool flipped = false;

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && nums[i - k] == -1) { // redo nums[i-k]
                flipped = !flipped;
            }

            if (nums[i] == flipped) {
                if (i + k > nums.size()) { // [i, i+k-1]
                    return -1;
                }

                nums[i] = -1; // -1 represent flipped
                flipped = !flipped;
                cnt++;
            }
        }

        return cnt;
    }
};
