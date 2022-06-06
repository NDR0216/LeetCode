class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        i = len(S)-1
        j = len(T)-1
        
        s = ''
        t = ''
        s_backspace = 0
        t_backspace = 0
        
        while i >= 0 or j >= 0:
            while i >= 0:
                if S[i] == '#':
                    s_backspace += 1
                    i -= 1
                elif s_backspace > 0:
                    s_backspace -= 1
                    i -= 1
                else:
                    s = S[i]
                    break

            while j >= 0:
                if T[j] == '#':
                    t_backspace += 1
                    j -= 1
                elif t_backspace > 0:
                    t_backspace -= 1
                    j -= 1
                else:
                    t = T[j]
                    break
                    
            if i < 0:
                s = ''
            if j < 0:
                t = ''
            
            if s == t:
                i -= 1
                j -= 1
            else:
                return False

        return True
