class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        path = {}
        
        for i in paths:
            src = i[0]
            dst = i[1]
            path[src] = dst
        
        src = paths[0][0]
        while(dst != 0):
            src = dst
            dst = path.get(src, 0)
            
        return src
