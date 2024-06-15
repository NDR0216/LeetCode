class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();

        // {capital, profit}
        vector<pair<int, int>> proj(n);
        for (int i = 0; i < n; i++) {
            proj[i] = {capital[i], profits[i]};
        }

        sort(proj.begin(), proj.end());

        priority_queue<int> pq;

        int idx = 0;
        while (k > 0) {
            while (idx < n && proj[idx].first <= w) {
                pq.push(proj[idx].second);
                idx++;
            }

            if (pq.empty()) { // no available proj
                return w;
            }

            w += pq.top();
            pq.pop();

            k--;
        }

        return w;
    }
};
