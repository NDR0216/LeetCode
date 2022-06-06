class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        substring = []
        
        for i in words:
            for j in words:
                if i != j and j.find(i) >= 0:
                    substring.append(i)
                    break

        return substring
