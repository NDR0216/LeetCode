class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr2.size(); i++) {
            freq[arr2[i]] = 0;
        }

        vector<int> tail;

        for (int i = 0; i < arr1.size(); i++) {
            unordered_map<int, int>::iterator found = freq.find(arr1[i]);

            if (found == freq.end()) { // not found
                tail.push_back(arr1[i]);
            } else {
                found->second++;
            }
        }

        vector<int> output(arr1.size());

        int idx = 0;
        for (int i = 0; i < arr2.size(); i++) {
            int cnt = freq[arr2[i]];
            while (cnt > 0) { // do cnt time
                output[idx] = arr2[i];
                idx++;

                cnt--;
            }
        }

        sort(tail.begin(), tail.end());
        move(tail.begin(), tail.end(), output.begin() + idx);

        return output;
    }
};
