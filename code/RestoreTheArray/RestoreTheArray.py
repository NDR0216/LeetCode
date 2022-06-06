class Solution:    
    def numberOfArrays(self, s: str, k: int) -> int:
        s_list = list(s)
        n = len(s)
        
        ans = [0] * n
        
        for i in range(n-1, -1, -1):
            if s_list[i] != '0':
                curr = []
                for j in range(i, n):
                    curr.append(s_list[j])
                    curr_str = "".join(curr)
                    if int(curr_str) <= k:
                        if j < n-1:
                            ans[i] = (ans[i]+ans[j+1])%1000000007
                        else:
                            ans[i] = (ans[i]+1)%1000000007
                    else:
                        break
                        
        return ans[0]%1000000007
