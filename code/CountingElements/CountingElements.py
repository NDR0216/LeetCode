class Solution:
    def countElements(self, arr: List[int]) -> int:
        cnt = {}
        
        for i in arr:
            value = cnt.get(i, 0)
            cnt[i] = value+1
            
        sums = 0
        for key, value in cnt.items():
            if (key+1) in cnt:
                sums += value
            
        return sums
