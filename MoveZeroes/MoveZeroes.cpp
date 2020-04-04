class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            if(*it == 0){
                nums.erase(it);
                zeros++;
                it--;
            }
        }
        
        for(int i = 0; i < zeros; i++){
            nums.push_back(0);
        }
    }
};
