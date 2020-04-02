class Solution:
    def generateTheString(self, n: int) -> str:
        if n%2==0:
            s = "a"*(n-1) + "b"
        else:
            s = "a"*(n)
            
        return s
