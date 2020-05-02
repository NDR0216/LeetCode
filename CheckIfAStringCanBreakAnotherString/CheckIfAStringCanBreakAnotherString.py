class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        n = len(s1)
        
        s1_dict = [0]*26
        s2_dict = [0]*26
        
        for i in s1:
            s1_dict[ord(i)-ord('a')] += 1
            
        for i in s2:
            s2_dict[ord(i)-ord('a')] += 1
        
        cnt_s1_gt_s2 = 0
        cnt_s2_gt_s1 = 0
        break_s1 = 1
        break_s2 = 1
        for i in range(26):
            cnt_s1_gt_s2 += s1_dict[i] - s2_dict[i]
            cnt_s2_gt_s1 += s2_dict[i] - s1_dict[i]
                
            if cnt_s1_gt_s2 < 0:
                break_s1 = 0
            if cnt_s2_gt_s1 < 0:
                break_s2 = 0
                
        if break_s1 == 1 or break_s2 == 1:
            return True
        else:
            return False
