class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        cnt = {}
        for i in nums:
            value = cnt.get(i, 0)
            if value == 0:
                cnt[i] = 1
            else:
                cnt[i] = value+1
                
        for key, value in cnt.items():
            if value == 1:
                return key
