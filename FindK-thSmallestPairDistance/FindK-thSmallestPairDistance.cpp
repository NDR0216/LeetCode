class Solution {
public:
    int count(vector<int>& nums, int dist) { // count # of pairs <= dist
        int cnt = 0;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > dist) {
                left++;
            }

            cnt += right - left;
        }

        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // binary search
        int left = 0, right = nums.back() - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = count(nums, mid);

            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left == right == lower_bound, 1 element

        return left;
    }
};
