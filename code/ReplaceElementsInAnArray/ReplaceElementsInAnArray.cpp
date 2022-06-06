class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> dict;
        
        for (int i = 0; i < operations.size(); i++) {
            map<int, int>::iterator it = dict.find(operations[i][0]);
            
            if (it != dict.end()) {
                dict[operations[i][1]] = dict[operations[i][0]];
                dict.erase(operations[i][0]); 
            } else {
                dict[operations[i][1]] = operations[i][0];
            }
            
        }
        
        map<int, int> dict_reversed;
        
        for (map<int,int>::iterator i = dict.begin(); i != dict.end(); ++i) {
            dict_reversed[i->second] = i->first;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator it = dict_reversed.find(nums[i]);
            
            if (it != dict_reversed.end()) {
                nums[i] = dict_reversed[nums[i]];
            }
        }
        
        return nums;
    }
};
