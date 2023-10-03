#Iterative Approach: Take 2 pointers l1 and l2 pointing to the first node of the LL
#Find smaller among l1 and l2 and store it in "answer"
#Shift the smaller one among l1 and l2 to next positon
#Case arises when l1 or l2 end 
#At that point append the other part to the "answer" 
#Finally return the merged list

# -------------ListNode class---------------------------------
#Create a linked list from scratch:
#Create a class ListNode, then create a constructor that will take [self, val=0, next=None] as param.
#Then assign the value to the node using self.val
# Initialize the next pointer to None (end of the list by default) using self.next = next

#-------------mergeTwoLists------------------------
#Now suppose we dont have l1 ie. if l1 is empty : Then as l2 is sorted the answer will be l1 right ? So we will return l2 using condition if not l1
#Now suppose we dont have l2: Then as l1 is sorted the answer will be l2 right ? So return l1 using condition if not l2. So these are our edge cases

#Now we can create a dummy node.We can put any value inside it not an issue : ans = ListNode(-1)
#Why we will use the dummy node ?
#By creating the dummy node, you have a starting point in the linked list even when there are no actual nodes, yet so it can help in attachments: aage aage lagane ko 
#Since Python variables store references to objects, both tail and ans now refer to the same dummy node object.So we can do tail = ans.

#Now let us use a while loop like we use for merge sort or merge sorted arrays: while l1 and l2:
#Till the while loop statisfies keep comparing l1 and l2.
#[For case when l1 is smaller] :  attach l1,Then move both tail and l1 forward to next position. 
#Do this by :  tail.next = l1, tail = l1 and l1 = l1.next
#[For case when l2 is smaller] : attach l2,Then move both tail and l2 forward to next position. 
#Do this by :  tail.next = l2, tail = l2, l2 = l2.next
# If l1 is not empty, attach the remaining nodes

#Case when l1 ends: if there are remaining nodes in l1. If l1 is not empty (i.e., it's not None), it means there are nodes left in l1 that need to be attached to the merged list.
#As tail represents the last node in the merged list, We can use tail.next = l1 that will attach all the remaining nodes in l1 
#So we can write         if l1: tail.next = l1

#case when l2 ends: if there are remaining nodes in l2. If l2 is not empty (i.e., it's not None), it means there are nodes left in l2 that need to be attached to the merged list.
#As tail represents the last node in the merged list, We can use tail.next = l2 that will attach all the remaining nodes in l2 
# So we can write        if l2: tail.next = l2

#Finally Skip the dummy node and return the merged list.Do this by : return ans.next



class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1, l2):
        # Edge case: If either list is empty, return the other list
        if not l1:
            return l2
        if not l2:
            return l1
        
        # Create a dummy node to simplify list construction
        ans = ListNode(-1)
        tail = ans
        
        # Iterate until both l1 and l2 become empty
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1  # Attach l1 to the merged list
                tail = l1       # Move tail forward
                l1 = l1.next    # Move l1 forward
            else:
                tail.next = l2  # Attach l2 to the merged list
                tail = l2       # Move tail forward
                l2 = l2.next    # Move l2 forward
        
        # If l1 is not empty, attach the remaining nodes
        if l1:
            tail.next = l1
        
        # If l2 is not empty, attach the remaining nodes
        if l2:
            tail.next = l2
        
        return ans.next  # Skip the dummy node and return the merged list
