class Solution:
    def numTeams(self, rating: List[int]) -> int:
        length = len(rating)
        
        num = 0
        num += self.recurr_greater(rating, 0, 0, 0, length)
        num += self.recurr_less(rating, 0, -1, 0, length)
        
        return num
        
    def recurr_greater(self, rating, idx, curr_rating, n, length):
        if n == 3:
            return 1
        elif idx >= length:
            return 0
        
        num = 0
        if rating[idx] > curr_rating:
            num += self.recurr_greater(rating, idx+1, rating[idx], n+1, length)
        num += self.recurr_greater(rating, idx+1, curr_rating, n, length)
        
        return num
    
    def recurr_less(self, rating, idx, curr_rating, n, length):
        if n == 3:
            return 1
        elif idx >= length:
            return 0
        
        num = 0
        if curr_rating == -1 or rating[idx] < curr_rating:
            num += self.recurr_less(rating, idx+1, rating[idx], n+1, length)
        num += self.recurr_less(rating, idx+1, curr_rating, n, length)
        
        return num
