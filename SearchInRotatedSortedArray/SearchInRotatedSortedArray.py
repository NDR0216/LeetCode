class Solution: 
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)-1
        while start <= end:
            mid = int((start+end)/2)

            print(start, mid, end)
            
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                if target <= nums[end] and nums[mid] > nums[end]:
                    start = mid+1
                else:
                    end = mid-1
            else:
                if target >= nums[start] and nums[mid] < nums[start]:
                    end = mid-1
                else:
                    start = mid+1
        
        return -1
