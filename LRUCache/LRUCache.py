class LRUCache:

    def __init__(self, capacity: int):
        self.keys = []
        self.dict = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        value = self.dict.get(key, -1)
        
        if value != -1:
            idx = self.keys.index(key)
            del self.keys[idx]
            self.keys.append(key)
        
        return value

    def put(self, key: int, value: int) -> None:
        self.dict[key] = value
        
        if key in self.keys:
            idx = self.keys.index(key)
            del self.keys[idx]
            self.keys.append(key)
        elif len(self.keys) >= self.capacity:
            evicts  = self.keys.pop(0)
            self.keys.append(key)
            del self.dict[evicts]
        else:
            self.keys.append(key)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
