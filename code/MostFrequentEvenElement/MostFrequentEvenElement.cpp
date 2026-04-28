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

        for (map<int, int>::iterator it = freq.begin(); it != freq.end();
             ++it) {
            if (it->second > max) {
                max = it->second;
                element = it->first;
            }
        }

        return element;
    }
};
