import math

class Solution:
    def maxDiff(self, num: int) -> int:
        num_list = []
        n = 0
        
        while(num != 0):
            digit = num%10
            num = int(num/10)
            
            num_list.insert(0, digit)
            n += 1
        
        find_a = 0
        find_b = 0
        replace_b = 0
        
        for i in range(n):
            if num_list[i] != 9:
                find_a = num_list[i]
                break
                
        for i in range(n):
            if num_list[i] > 1:
                find_b = num_list[i]
                if i == 0:
                    replace_b = 1
                else:
                    replace_b = 0
                break
        
        a = 0
        b = 0
        
        for i in range(n):
            if num_list[i] == find_a:
                a = a*10+9
            else:
                a = a*10+num_list[i]
                
            if num_list[i] == find_b:
                b = b*10+replace_b
            else:
                b = b*10+num_list[i]
                
        return a-b
