class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        // sort idx by pos
        vector<pair<int, int>> robots(n); // (pos, idx)
        for (int i = 0; i < n; i++) {
            robots[i] = {positions[i], i};
        }

        sort(robots.begin(), robots.end());

        stack<int> R;   // store the idx of robot
        for (int i = 0; i < n; i++) {
            int idx = robots[i].second;

            if (directions[idx] == 'R') {
                R.push(idx);
            } else {
                while (!R.empty() && healths[idx] > 0) {    // there's collision
                    if (healths[R.top()] > healths[idx]) {
                        healths[idx] = 0;
                        healths[R.top()]--;
                    } else if (healths[R.top()] < healths[idx]) {
                        healths[idx]--;
                        healths[R.top()] = 0;
                        R.pop();
                    } else {
                        healths[idx] = 0;
                        healths[R.top()] = 0;
                        R.pop();
                    }
                }
            }
        }

        vector<int> remaining;
        for (int i = 0; i < n; i++) {
            if (healths[i] != 0) {
                remaining.push_back(healths[i]);
            }
        }

        return remaining;
    }
};
