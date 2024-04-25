class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers_base2;
        
        int i = 0;
        while (n != 0) {
            if (n % 2 == 1) {
                powers_base2.push_back(i);
            }
            n = n >> 1;
            i++;
        }
        
        vector<int> answers(queries.size(), 0);
        
        for (int i = 0; i < queries.size(); i++) {
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                answers[i] += powers_base2[j];
                // answers[i] = answers[i] % 1000000007;
            }
            
            int two_30 = int(pow(2.0, 30)) % 1000000007;
            
            long long int temp = 1;
            while (answers[i] >= 30) {
                temp *= two_30;
                temp %= 1000000007;
                answers[i] -= 30;
            }
            
            temp *= pow(2.0, answers[i]);
            temp %= 1000000007;
            
            answers[i] = temp;
        }
        
        return answers;
    }
};
