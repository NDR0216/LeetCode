class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        record = []
        anagrams = []
        for i in strs:
            
            chars = {}
            for j in i:
                value = chars.get(j, 0)
                chars[j] = value+1
            
            if chars in record:
                idx = record.index(chars)
                anagrams[idx].append(i)
            else:
                record.append(chars)
                anagrams.append([i])
        
        return anagrams
