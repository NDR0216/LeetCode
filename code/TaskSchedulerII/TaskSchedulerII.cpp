class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long days = 0; 
        
        map<int, long> dict;
        for (int i = 0; i < tasks.size(); i++) {
            if (dict.count(tasks[i]) > 0) {
                if (days < dict[tasks[i]]) {
                    days = dict[tasks[i]];
                }
            }
            days++;
            
            dict[tasks[i]] = long(days + space);
        }
        
        return days;
    }
};
