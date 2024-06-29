class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int* degree = new int[n]();

        for (int i = 0; i < roads.size(); i++) {
            int a_i = roads[i][0];
            int b_i = roads[i][1];

            degree[a_i]++;
            degree[b_i]++;
        }

        sort(degree, degree + n);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)(i + 1) * degree[i];
        }

        return sum;
    }
};
