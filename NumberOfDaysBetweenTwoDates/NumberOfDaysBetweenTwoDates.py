class Solution:
    def convert_month(self, x):
        return {
            1: 0,
            2: 31,
            3: 59,
            4: 90,
            5: 120,
            6: 151,
            7: 181,
            8: 212,
            9: 243,
            10: 273,
            11: 304,
            12: 334,
        }[x]
    
    def convert_1971(self, yr, month, day):
        num = 365*(yr-1971)
        num += int((yr-1)/4) - int(1970/4)
        num -= int((yr-1)/100) - int(1970/100)
        num += int((yr-1)/400) - int(1970/400)
        
        num += self.convert_month(month)
        
        if month > 2:
            if yr%4 == 0 and yr%100 != 0:
                num +=1
            elif yr%400 == 0:
                num +=1
            
        num += day
            
        return num
        
    
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        yr1 = int(date1[0:4])
        month1 = int(date1[5:7])
        day1 = int(date1[8:10])
        yr2 = int(date2[0:4])
        month2 = int(date2[5:7])
        day2 = int(date2[8:10])
        
        num1 = self.convert_1971(yr1, month1, day1)
        num2 = self.convert_1971(yr2, month2, day2)
        
        return abs(num1-num2)
