class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> min_freq;
        for (int i = 0; i < words[0].size(); i++) {
            min_freq[words[0][i]]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> freq;
            for (int j = 0; j < words[i].size(); j++) {
                freq[words[i][j]]++;
            }

            for (unordered_map<char, int>::iterator it = min_freq.begin();
                 it != min_freq.end(); ++it) {
                char key = it->first;
                int& value = it->second;

                value = min(value, freq[key]);
            }
        }

        vector<string> answer;
        for (unordered_map<char, int>::iterator it = min_freq.begin();
             it != min_freq.end(); ++it) {
            char key = it->first;
            int value = it->second;

            while (value > 0) { // do value times
                answer.push_back(string(1, key));
                value--;
            }
        }

        return answer;
    }
};
