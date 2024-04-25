class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> dict;
        
        for (int i = 0; i < items1.size(); i++) {
            dict[items1[i][0]] = items1[i][1];
        }
        
        for (int i = 0; i < items2.size(); i++) {
            if (dict.count(items2[i][0]) > 0) {
                dict[items2[i][0]] += items2[i][1];
            } else {
                dict[items2[i][0]] = items2[i][1];
            }
        }
        
        vector<vector<int>> ret;
        for (map<int,int>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
            vector<int> temp(2);
            temp[0] = iter->first;
            temp[1] = iter->second;
            ret.push_back(temp);
        }
        
        return ret;
    }
};
