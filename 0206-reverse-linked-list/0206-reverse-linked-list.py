#Just as in diagram : take two pointers curr(pointing to 1st node) and prev (pointing to NULL)
# We want to keep going till we reach the end of the list using condition: while curr is not null
#Then we reverse the pointers : by curr.next = prev
#Then we can shift our pointers : prev=curr, curr=curr.next
#We can store this curr.next in 1st line in a variable called "nxt" so that we can use it later (in place of curr.next while shifting of pointers)
#Lastly we return the result ie. prev because at the last step of our approach 

class Solution(object):
    def reverseList(self, head):
        prev, curr = None, head
        while curr: 
            temp=curr.next #added at last
            curr.next=prev
            prev=curr
            curr=temp
        return prev









# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next