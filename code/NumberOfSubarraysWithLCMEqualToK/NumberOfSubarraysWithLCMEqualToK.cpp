class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int subarrays = 0;
        
        int len = 0;
        int sub_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) {
                subarrays += (len-sub_len)*(sub_len+1);
                
                len += 1;
                sub_len = 0;
            } else if (k % nums[i] == 0) {
                len++;
                sub_len++;
            } else {
                subarrays += (len-sub_len)*(sub_len+1);

                len = 0;
                sub_len = 0;
            }
        }
        subarrays += (len-sub_len)*(sub_len+1);
        
        return subarrays;
    }
};
