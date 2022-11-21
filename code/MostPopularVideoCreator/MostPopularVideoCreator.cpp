class Solution {
public:
    struct tuple {
      int view;
      string id;
    };
    
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> array;
        
        map<string, long int> dict_views;
        map<string, tuple> dict_id;
        
        for (int i = 0; i < creators.size(); i++) {
            if (dict_views.count(creators[i]) == 0) {
                dict_views[creators[i]] = views[i];
            } else {
                dict_views[creators[i]] += views[i];
            }
            
            if (dict_id.count(creators[i]) == 0 || dict_id[creators[i]].view < views[i] || (dict_id[creators[i]].view == views[i] && dict_id[creators[i]].id > ids[i])) {
                struct tuple t = {views[i], ids[i]};
                
                dict_id[creators[i]] = t;
            }
        }
        
        long int max = 0;
        for (map<string, long int>::iterator iter = dict_views.begin(); iter != dict_views.end(); ++iter) {
            if (iter->second > max) {
                max = iter->second;
                
                array.clear();
                vector<string> temp(2);
                temp[0] = iter->first;
                temp[1] = dict_id[iter->first].id;
                array.push_back(temp);
            } else if (iter->second == max) {
                vector<string> temp(2);
                temp[0] = iter->first;
                temp[1] = dict_id[iter->first].id;
                array.push_back(temp);
            }
        }
        
        return array;
    }
};
