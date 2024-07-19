class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int min_enemy = INT_MAX;

        long long sum = 0;
        for (int i = 0; i < enemyEnergies.size(); i++) {
            min_enemy = min(min_enemy, enemyEnergies[i]);
            sum += enemyEnergies[i];
        }

        if (currentEnergy < min_enemy) {
            return 0;
        }

        return (sum + currentEnergy - min_enemy) / min_enemy;
    }
};
