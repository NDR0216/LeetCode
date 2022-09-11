class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                freq[nums[i]] += 1; 
            }
        }
        
        int max = 0;
        int element = -1;
        
        for (map<int, int>::iterator iter = freq.begin(); iter != freq.end(); ++iter) {
            if (iter->second > max) {
                max = iter->second;
                element = iter->first;
            }
        }
        
        return element;
    }
};
