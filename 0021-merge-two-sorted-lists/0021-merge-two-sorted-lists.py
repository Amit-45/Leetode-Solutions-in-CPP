#Recursive Approach: Take 2 pointers l1 and l2 (pointing to the 1st nodes of each linked list)
#I will now find which is smaller among l1 and l2. The one that is smaller will be the gloabal minima (as both the LL are sorted). Suppose l1 is smaller 
# Then i will say Recursion to sort everything from l1's next till the end 
#After that what I will do is attach this sorted part(from l1's next till the end) to the global minima that is l1. Finally we get our answer after attaching.

# -------------ListNode class---------------------------------
#Create a linked list from scratch:
#Create a class ListNode, then create a constructor that will take [self, val=0, next=None] as param.
#Then assign the value to the node using self.val
# Initialize the next pointer to None (end of the list by default) using self.next = next

#---------------- recursive function called merge----------------
#It takes 3 params(self, l1 and l2)

#Now suppose we dont have l1 ie. if l1 is empty : Then as l2 is sorted the answer will be l1 right ? So we will return l2 using condition if not l1
#Now suppose we dont have l2: Then as l1 is sorted the answer will be l2 right ? So return l1 using condition if not l2. So these are our base cases

#Now lets compare l1 and l2 using condition if(l1.val<l1.val)  and (else) 
#If the conditon l1.val<l1.val satisfies, we will have to l1 as it will the global minima 
#Now we will tell recursion to sort every thing after l1's next till the end  : self.merge(l1.next, l2)
#After recursion sorts (l1's next till the end ) we will  attach this sorted part(from l1's next till the end) to the global minima l1 by : l1.next = self.merge(l1.next, l2)
#Then we will return l1, the code ensures that the smaller value becomes the head of the merged list, 

#Now comes the else part (it handles both conditions l1.val<l1.val and l1.val==l1.val):
# We do l2->next 
#As we have already taken a node of l2,we keep l1 as it is and we will take everything after and give recursion to merge: l2.next = self.merge(l1, l2.next)
#Then we will return l2, the code ensures that the smaller value becomes the head of the merged list

#-----------------mergeTwoLists function -------------------------------------
#We sill pass both the linked list in this function
#return self.merge(list1, list2)

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def merge(self, l1, l2):
        # Base case: If either list is empty, return the other list
        if not l1:
            return l2
        if not l2:
            return l1

        # Compare the values of the current nodes
        if l1.val < l2.val:
            l1.next = self.merge(l1.next, l2)
            return l1
        else:
            l2.next = self.merge(l1, l2.next)
            return l2

    def mergeTwoLists(self, list1, list2):
        return self.merge(list1, list2)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next