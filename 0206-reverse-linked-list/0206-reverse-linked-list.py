#Given: head->1->2->3->4
#After recursion part reversed the part from 2 to 4 and returned a new head : ->1->[2<-3<-4]<-head 

#---------------reverse function--------------------------------
#Create a function named reverse that would take params (self,head)
#Create a "reverse_head" variable that will return the new head after reversing using recursion
#Recursion call would be something like: reverse_head = self.reverse(head.next) which was as mentioned was going to give a new head
#Then my work :-
#   =>Link 2 and 1  (head.next.next = head)(i am telling 2 to point to head node ie 1)
#   =>Link 1 and None (head.next = None) (i am telling 1 to point to None)
#Finally return the reverse Head

#-----------Base case for reverse function-----------------
# -If the list has only one node: it returns the same node because reversing a single-node list results in the same list (Checked with condition :if not head.next)
# -If the list has no node or Empty node:(Checked with condition :if not head)

#---------reverseList function------------------------------
#It will simply return the head after the reverse


class Solution(object):
    def reverse(self, head):
        # Base case for recursion
        if not head or not head.next:
            return head
        
        reverse_head = self.reverse(head.next) #recursive call
        head.next.next = head 
        head.next = None
        return reverse_head

    def reverseList(self, head):
        return self.reverse(head)


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next