class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        
        vector<int> answer(queries.size(), nums.size());
        
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (queries[i] < nums[j]) {
                    answer[i] = j;
                    break;
                }
            }
        }
        
        return answer;
    }
};
