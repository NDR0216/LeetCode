class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int temp[31] = {0};
        
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            while(nums[i] != 0) {
                if (nums[i]%2 == 1) {
                    temp[j]++;
                }
                
                nums[i] = nums[i]/2;
                j++;
            }
        }
        
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            ans = ans << 1;
            if (temp[i] > 0) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
