class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min;
        
        int whites = 0;
        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whites++;
            }
        }
        
        min = whites;
        
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i-k] == 'W') {
                whites--;
            }
            if (blocks[i] == 'W') {
                whites++;
            }
            
            if (min > whites) {
                min = whites;
            }
        }
        return min;
    }
};
