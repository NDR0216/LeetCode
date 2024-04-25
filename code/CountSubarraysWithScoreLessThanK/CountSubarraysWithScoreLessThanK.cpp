class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long int subarrays = 0;
        
        long int sum[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                sum[i] = sum[i-1] + nums[i];
            } else {
                sum[i] = nums[i];
            }
        }
        
        long int length = 0;
        for (int i = 0; i < nums.size(); i++) {
            length += 1;
            while (length != 0 && (i >= length && ((sum[i] - sum[i-length]) * length) >= k) || (i < length && (sum[i]* length) >= k)) {
                length -= 1;
            }
            
            subarrays += length;
        }
        
        return subarrays;
    }
};
