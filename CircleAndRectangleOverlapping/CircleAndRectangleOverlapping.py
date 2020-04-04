class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        if (abs(x1 - x_center) <= radius or abs(x2 - x_center) <= radius) and y1 <= y_center <= y2:
            return True
        elif (abs(y1 - y_center) <= radius or abs(y2 - y_center) <= radius) and x1 <= x_center <= x2:
            return True
        
        if (abs((x1 - x_center)**2+(y1 - y_center)**2) <= radius**2):
            return True
        elif (abs((x1 - x_center)**2+(y2 - y_center)**2) <= radius**2):
            return True
        elif (abs((x2 - x_center)**2+(y1 - y_center)**2) <= radius**2):
            return True
        elif (abs((x2 - x_center)**2+(y2 - y_center)**2) <= radius**2):
            return True
        
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        
        return False
