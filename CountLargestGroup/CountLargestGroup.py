class Solution:
    def countLargestGroup(self, n: int) -> int:
        size = {}
        
        for i in range(1, n+1):
            sum = 0
            while(i != 0):
                sum += i%10
                i = int(i/10)
            
            value = size.get(sum, 0)
            size[sum] = value+1
        
        max = 0
        max_cnt = 0
        
        for value in size.values():
            if value > max:
                max = value
                max_cnt = 1
            elif value == max:
                max_cnt += 1
                
        return max_cnt
