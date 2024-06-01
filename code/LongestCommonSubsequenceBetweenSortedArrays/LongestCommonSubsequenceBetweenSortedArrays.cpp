class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int* idx = new int[arrays.size()]();

        vector<int> subseq;
        for (int i = 0; i < arrays[0].size(); i++) {
            int element = arrays[0][i];

            bool flag = true;
            for (int j = 1; j < arrays.size(); j++) {
                while (idx[j] < arrays[j].size() &&
                       arrays[j][idx[j]] < element) {
                    idx[j]++;
                }

                if (idx[j] == arrays[j].size()) {
                    return subseq;
                }

                if (arrays[j][idx[j]] != element) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                subseq.push_back(element);
            }
        }

        return subseq;
    }
};
