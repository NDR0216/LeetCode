class NumberContainers {
public:
    map<int, int> dict_idx;
    map<int, vector<int>> heaps;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (dict_idx[index] != number) {
            if (heaps.count(dict_idx[index]) != 0) {
                for (int i = 0; i < heaps[dict_idx[index]].size(); i++) {
                    if (heaps[dict_idx[index]][i] == index) {
                        heaps[dict_idx[index]].erase(heaps[dict_idx[index]].begin()+i);
                        make_heap(heaps[dict_idx[index]].begin(), heaps[dict_idx[index]].end(), greater<int>());
                        break;
                    }
                }
            }
            
            
            dict_idx[index] = number;
            if (heaps.count(number) == 0) {
                vector<int> temp;
                heaps[number] = temp;
            }
            heaps[number].push_back(index);
            push_heap(heaps[number].begin(), heaps[number].end(), greater<int>());
        }
        

    }
    
    int find(int number) {
        if (heaps.count(number) == 0) {
            return -1;
        }
        if (heaps[number].empty()) {
            return -1;
        }
        return heaps[number].front();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
