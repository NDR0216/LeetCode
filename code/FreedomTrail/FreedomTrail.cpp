class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();

        unordered_map<char, vector<int>> char_idx;
        for (int i = 0; i < ring.size(); i++) {
            char_idx[ring[i]].push_back(i);
        }

        vector<int> steps(1);
        for (int i = 0; i < key.size(); i++) {
            vector<int> next_steps(char_idx[key[i]].size());

            for (int j = 0; j < char_idx[key[i]].size(); j++) {
                int next_idx = char_idx[key[i]][j];

                next_steps[j] = INT_MAX;
                for (int k = 0; k < steps.size(); k++) {
                    int idx;

                    if (i == 0) {
                        idx = 0;
                    } else {
                        idx = char_idx[key[i - 1]][k];
                    }

                    int dist =
                        min(abs(next_idx - idx), n - abs(next_idx - idx));

                    next_steps[j] = min(next_steps[j], steps[k] + dist);
                }
            }

            steps = next_steps;
        }

        int min_step = steps[0];
        for (int i = 1; i < steps.size(); i++) {
            min_step = min(min_step, steps[i]);
        }

        return min_step + key.size();
    }
};
