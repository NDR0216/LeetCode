class Solution {
private:
    const int WHEEL = 4;

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.find("0000") != visited.end()) { // "0000" is in daedends
            return -1;
        }

        queue<string> q;

        visited.insert("0000");
        q.push("0000");

        int turns = 0;
        while (!q.empty()) {
            for (int _ = q.size(); _ > 0; _--) {
                string v = q.front();
                q.pop();

                if (v == target) {
                    return turns;
                }

                for (int i = 0; i < WHEEL; i++) {
                    string u_1 = v;
                    string u_2 = v;
                    if (v[i] == '0') {
                        u_1[i] += 1;
                        u_2[i] = '9';
                    } else if (v[i] == '9') {
                        u_1[i] = '0';
                        u_2[i] -= 1;
                    } else {
                        u_1[i] += 1;
                        u_2[i] -= 1;
                    }

                    if (visited.find(u_1) == visited.end()) { // not visited
                        visited.insert(u_1);
                        q.push(u_1);
                    }
                    if (visited.find(u_2) == visited.end()) {
                        visited.insert(u_2);
                        q.push(u_2);
                    }
                }
            }

            turns++;
        }

        return -1;
    }
};
