class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        frog = [0]*4 # 'c', 'r', 'o', 'k'
        sum_frog = 0
        
        max = 0
        for i in croakOfFrogs:
            if i == 'c':
                frog[0] += 1
                sum_frog += 1
                if sum_frog > max:
                    max = sum_frog
            elif i == 'r':
                if frog[0] > 0:
                    frog[0] -= 1
                    frog[1] += 1
                else:
                    return -1
            elif i == 'o':
                if frog[1] > 0:
                    frog[1] -= 1
                    frog[2] += 1
                else:
                    return -1
            elif i == 'a':
                if frog[2] > 0:
                    frog[2] -= 1
                    frog[3] += 1
                else:
                    return -1
            elif i == 'k':
                if frog[3] > 0:
                    frog[3] -= 1
                    sum_frog -= 1
                else:
                    return -1
            else:
                    return -1
        
        if sum_frog == 0:
            return max
        else:
