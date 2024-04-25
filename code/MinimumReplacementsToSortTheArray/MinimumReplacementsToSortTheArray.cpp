class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operations = 0;
        
        int i = nums.size()-1;
        int temp = nums[i];
        while (i >= 0) {
            
            if (nums[i] > temp) {
                int ratio = nums[i]/temp;
                
                if (nums[i] % temp == 0) {
                    operations += ratio-1;
                    temp = nums[i] / ratio;
                } else {
                    operations += ratio;
                    temp = nums[i] / (ratio+1);
                }
                
            } else {
                temp = nums[i];
                
            }
            
            i--;
        }
        
        return operations;
    }
};
