class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fib = []
        
        i = 0
        while(i == 0 or fib[i-1] <= k):
            if i > 1:
                fib.append(fib[i-1] + fib[i-2])
            else:
                fib.append(1)
                
            i += 1
        
        n = len(fib)
        ans = 0
        while(k > 0):
            for i in range(n):
                if fib[i] > k:
                    k -= fib[i-1]
                    ans += 1
                    break
        
        return ans
