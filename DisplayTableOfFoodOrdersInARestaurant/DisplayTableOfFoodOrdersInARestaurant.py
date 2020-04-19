class Solution:
    def quickSort(self, arr, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        
        pivot = arr[begin]
        
        while left < right:
            while left < right and pivot <= arr[right]:
                right -= 1
            arr[left] = arr[right]
            while left < right and pivot > arr[left]:
                left += 1
            arr[right] = arr[left]
            
                
        arr[left] = pivot
            
        self.quickSort(arr, begin, left-1)
        self.quickSort(arr, left+1, end)
        return
    
    def intQuickSort(self, arr, begin, end):
        if begin >= end:
            return
        
        left = begin
        right = end
        
        pivot = arr[begin]
        
        while left < right:
            while left < right and int(pivot) <= int(arr[right]):
                right -= 1
            arr[left] = arr[right]
            while left < right and int(pivot) > int(arr[left]):
                left += 1
            arr[right] = arr[left]
            
                
        arr[left] = pivot
            
        self.intQuickSort(arr, begin, left-1)
        self.intQuickSort(arr, left+1, end)
        return
    
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        food_entry = set() #set
        table_entry = set()
        record = {} #dict
        
        for i in orders:
            table = i[1]
            food = i[2]
            
            food_entry.add(food)
            table_entry.add(table)
            if table not in record.keys():
                record[table] = {}
            value = record[table].get(food, 0)
            record[table][food] = value+1
            
        food_entry_list = list(food_entry)
        n_food_entry = len(food_entry)
        table_entry_list = list(table_entry)
        n_table_entry = len(table_entry)
        
        self.quickSort(food_entry_list, 0, n_food_entry-1)
        self.intQuickSort(table_entry_list, 0, n_table_entry-1)
        
        ans = []
        
        ans.append(["Table"])
        ans[0].extend(food_entry_list)
        row = 1
        for i in table_entry_list:
            ans.append([])
            ans[row].append(i)
            for j in food_entry_list:
                value = record[i].get(j, 0)
                ans[row].append(str(value))
            row += 1
            
        return ans
