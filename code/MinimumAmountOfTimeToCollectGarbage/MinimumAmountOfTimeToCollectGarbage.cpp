class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int minute = 0;
        
        int M = 0;
        int P = 0;
        int G = 0;
        
        int travel_min = 0;
        
        for (int i = 0; i < garbage.size(); i++) {
            minute += garbage[i].length();
            
            for (int j = 0; j < garbage[i].length(); j++) {
                switch(garbage[i][j]) {
                    case 'M':
                        M = travel_min;
                        break;
                    case 'P':
                        P = travel_min;
                        break;
                    case 'G':
                        G = travel_min;
                        break;
                }
            }
            
            if (i < garbage.size()-1) {
                travel_min += travel[i];
            }
        }
        
        minute += M + P + G;
        
        return minute;
    }
};
