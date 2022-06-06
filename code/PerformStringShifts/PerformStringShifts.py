class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        length = len(s)
        
        shift_cnt = 0
        
        for i in shift:
            if i[0] == 1:
                shift_cnt += i[1]
            else:
                shift_cnt -= i[1]
        
        shift_cnt = shift_cnt % length        
        
        s_shift = s[-shift_cnt:] + s[0:-shift_cnt]
        
        return s_shift
