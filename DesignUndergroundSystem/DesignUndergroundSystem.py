class UndergroundSystem:

    def __init__(self):
        self.AverageTime = {}
        self.record = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.record[id] = (stationName, t)
        return

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation = self.record[id][0]
        time = t - self.record[id][1]
        
        value = self.AverageTime.get((startStation, stationName), (0, 0))
        
        if value == (0, 0):
            self.AverageTime[(startStation, stationName)] = (time, 1)
        else:
            self.AverageTime[(startStation, stationName)] = (value[0]+time, value[1]+1)
        return

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        sum, n = self.AverageTime[(startStation, endStation)]
        
        return float(sum/n)
        
        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
