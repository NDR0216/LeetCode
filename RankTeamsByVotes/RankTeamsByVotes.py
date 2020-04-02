class Solution:
    def compare_rank(self, a, b, a_char, b_char):
        for i, j in zip(a, b):
            if i > j:
                return True
            elif i < j:
                return False
            
        if a_char > b_char:
            return False
        elif a_char < b_char:
            return True
        
        return True
        
    def quickSort(self, arr, rank, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        pivot = arr[left]
        pivot_rank = rank[left]
        while left < right:
            while left < right and self.compare_rank(rank[right], pivot_rank, arr[right], pivot):
                right -= 1
            arr[left] =  arr[right]
            rank[left] = rank[right]
            while left < right and self.compare_rank(pivot_rank, rank[left], pivot, arr[left]):
                left += 1
            arr[right] = arr[left]
            rank[right] = rank[left]
        arr[left] = pivot
        rank[left] = pivot_rank
        
        self.quickSort(arr, rank, begin, left-1)        
        self.quickSort(arr, rank, left+1, end)
        
        return
    
    def rankTeams(self, votes: List[str]) -> str:
        num_char = len(votes[0])
        rank = [[0] * num_char for i in range(num_char)]
        
        for i in votes:
            for j in range(num_char):
                idx = votes[0].index(i[j])
                rank[idx][j] += 1
                
        ans = list(votes[0])
        
        self.quickSort(ans, rank, 0, num_char-1)
        
        ans.reverse()
        
        ans_str = ''.join(ans)
        
        return ans_str
