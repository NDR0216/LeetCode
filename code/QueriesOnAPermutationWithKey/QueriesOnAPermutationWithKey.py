class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        P = list(range(1, m+1))
        result = []
        
        for i in queries:
            pos = P.index(i)
            del P[pos]
            result.append(pos)
            P.insert(0, i)
        
        return result
