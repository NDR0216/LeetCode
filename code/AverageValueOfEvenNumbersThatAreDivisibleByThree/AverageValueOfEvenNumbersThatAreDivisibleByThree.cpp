class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 6 == 0) {
                sum += nums[i];
                cnt++;
            }
        }
        
        if (cnt == 0) {
            return 0;
        } else {
            return sum/cnt;
        }
    }
};
