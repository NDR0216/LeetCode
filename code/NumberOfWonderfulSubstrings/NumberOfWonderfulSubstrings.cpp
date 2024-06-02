class Solution {
private:
    static const int LETTER = 10;

public:
    long long wonderfulSubstrings(string word) {
        unordered_map<bitset<LETTER>, int> hashmap;

        bitset<LETTER> bitmask;

        hashmap[bitmask] = 1;

        long long wonderful = 0;
        for (int i = 0; i < word.size(); i++) {
            bitmask.flip(word[i] - 'a');

            wonderful += hashmap[bitmask];

            hashmap[bitmask] += 1;

            for (int j = 0; j < LETTER; j++) {
                bitmask.flip(j);

                wonderful += hashmap[bitmask];

                bitmask.flip(j);
            }
        }

        return wonderful;
    }
};
