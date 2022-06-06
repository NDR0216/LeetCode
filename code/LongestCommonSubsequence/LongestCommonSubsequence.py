class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1 = len(text1)
        n2 = len(text2)
        
        subsequence = [[None for i in range(n2)] for j in range(n1)]
        
        for i in range(n1-1, -1, -1):
            for j in range(n2-1, -1, -1):
                if text1[i] == text2[j]:
                    if i >= n1-1 or j >= n2-1:
                        subsequence[i][j] = 1
                    else:
                        subsequence[i][j] = subsequence[i+1][j+1] + 1
                else:
                    if i >= n1-1 and j >= n2-1:
                        subsequence[i][j] = 0
                    elif i >= n1-1:
                        subsequence[i][j] = subsequence[i][j+1]
                    elif j >= n2-1:
                        subsequence[i][j] = subsequence[i+1][j]
                    else:
                        subsequence[i][j] = max(subsequence[i+1][j], subsequence[i][j+1])

        return subsequence[0][0]
