class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA,
                             vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();

        long long dp_A = 0;      // dp_A[i]
        long long dp_B = 0;      // dp_B[i]
        long long last_dp_A = 0; // dp_A[i-1]
        long long last_dp_B = 0; // dp_B[i-1]

        for (int i = 0; i < n; i++) {
            long long next_dp_A = max(dp_A, last_dp_B) + energyDrinkA[i];
            long long next_dp_B = max(dp_B, last_dp_A) + energyDrinkB[i];

            last_dp_A = dp_A;
            dp_A = next_dp_A;
            last_dp_B = dp_B;
            dp_B = next_dp_B;
        }

        return max(dp_A, dp_B);
    }
};
