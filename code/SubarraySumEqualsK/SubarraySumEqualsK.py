class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sums = {0: 1}
        
        sum = 0
        cnt = 0
        for i in nums:
            sum += i

            value = sums.get(sum-k, 0)
            cnt += value
            
            value = sums.get(sum, 0)
            sums[sum] = value+1
                
        return cnt
