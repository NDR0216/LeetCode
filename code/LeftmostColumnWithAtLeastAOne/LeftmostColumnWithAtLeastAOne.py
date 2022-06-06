# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        [n, m] = binaryMatrix.dimensions()
        
        leftmost = -1
        for i in range(n):
            left = 0
            right = m-1
            
            one = -1
            while left <= right:
                mid = int((left+right)/2)
                if binaryMatrix.get(i, mid) == 1:
                    right = mid-1
                    one = mid
                else:
                    left = mid+1
                    
            if one != -1:
                if leftmost == -1 or leftmost > one:
                    leftmost = one

        return leftmost
