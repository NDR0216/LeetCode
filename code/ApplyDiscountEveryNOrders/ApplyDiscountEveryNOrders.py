class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.discount = discount
        self.products = products
        self.prices = prices
        self.count = 0

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.count += 1
        sum = 0
        
        for i, j in zip(product, amount):
            idx =  self.products.index(i)
            sum += self.prices[idx] * j
               
        if self.count == self.n:
            sum *= (100-self.discount)/100
            self.count = 0
        
        return sum
