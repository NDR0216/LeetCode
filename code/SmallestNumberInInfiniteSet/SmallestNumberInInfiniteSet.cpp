class SmallestInfiniteSet {
public:
    int smallest;
    map<int, bool> dict;
    
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            dict[i] = true;
        }
    }
    
    int popSmallest() {
        map<int, bool>::iterator iter=dict.begin();
        int smallest = iter->first;
        dict.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        dict[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
