class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size());
        
        stack<int> temps;
        stack<int> idxs;
        
        for (int i = 0; i < temperatures.size(); i++) {
            while(!temps.empty() && temps.top() < temperatures[i]) {
                days[idxs.top()] = i - idxs.top();
                temps.pop();
                idxs.pop();                
            }
            
            temps.push(temperatures[i]);
            idxs.push(i);
        }
        
        return days;
    }
};
