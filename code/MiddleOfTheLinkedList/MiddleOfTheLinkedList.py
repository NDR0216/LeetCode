# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        
        middle = head
        a = head
        while a.next != None and a.next.next != None:
            middle = middle.next
            a = a.next.next
        
        if a.next != None:
            middle = middle.next
        
        return middle
