class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int number = 0;
        
        
        int* dict1 = new int[diff];
        int* dict2 = new int[diff];
        
        for (int i = 0; i < diff; i++) {
            dict1[i] = 0;
            dict2[i] = 0;
        }
        
        
        for (int i = 0; i < nums.size(); i++) {            
            if (nums[i] == dict1[nums[i]%diff]+diff) {
                dict2[nums[i]%diff]++;
            } else {
                dict2[nums[i]%diff] = 1;
            }
            
            dict1[nums[i]%diff] = nums[i];
            
            if (dict2[nums[i]%diff] > 2) {
                number++;
            }
        }
        
        return number;
    }
};
