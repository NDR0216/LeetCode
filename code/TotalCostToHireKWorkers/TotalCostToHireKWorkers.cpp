class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        vector<int> heap_left;
        vector<int> heap_right;
        
        int idx_left;
        int idx_right;
            
        for (int i = 0; i < candidates; i++) {            
            heap_left.push_back(costs[i]);
        }
        make_heap(heap_left.begin(), heap_left.end(), greater<int>());
        
        for (int i = costs.size()-1; i >= costs.size()-candidates && i >= candidates; i--) {
            heap_right.push_back(costs[i]);
        }
        make_heap(heap_right.begin(), heap_right.end(), greater<int>());

        idx_left = candidates;
        if (costs.size()-candidates >= candidates) {
            idx_right = costs.size()-candidates-1;
        } else {
            idx_right = candidates-1;
        }

        long long total = 0;
        for (int i = 0; i < k; i++) {
            if (!heap_left.empty() && (heap_right.empty() || heap_left[0] <= heap_right[0])) {
                pop_heap(heap_left.begin(), heap_left.end(), greater<int>());
                total += heap_left.back();
                heap_left.pop_back();

                if (idx_left < costs.size() && idx_left <= idx_right) {
                    heap_left.push_back(costs[idx_left]);
                    push_heap(heap_left.begin(), heap_left.end(), greater<int>());
                    idx_left++;
                }
            } else {
                pop_heap(heap_right.begin(), heap_right.end(), greater<int>());
                total += heap_right.back();
                heap_right.pop_back();

                if (idx_right >= 0 && idx_right >= idx_left) {
                    heap_right.push_back(costs[idx_right]);
                    push_heap(heap_right.begin(), heap_right.end(), greater<int>());
                    idx_right--;
                }
            }
        }

        return total;
    }
};
