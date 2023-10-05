#------------------------MIN HEAP METHOD-----------------------------
#Approach:-
#Create a min heap(By default heap is min heap in python)
#This approach optimally takes advantage of the fact that the input lists are already sorted.
#Lets maintain a heap of size k, and in each iteration, you pop the smallest element from the heap and add it to the merged list
#Explain that you always attach nodes to dummy.next, which eliminates the need for special cases when adding the first node.

#------------ListNode-------------
#Create a ListNode class that contains val and next (default values of 0 and none)
#-----------mergeKLists-----------
#Create an empty min heap by : heap = []
#Create the dummy node ho handle edge cases easily when adding to the first node  :  dummy = ListNode(-1)
#At this point, both tail and dummy are references to the same node, which is the dummy node with a value of -1. So : tail = dummy
#Iterate over all the heads , lists is a collection of linked lists, where each head represents the starting node of a linked list. So: for head in lists:

# head.val: This is accessing the val attribute of the head node. In the context of a linked list, val typically represents the value stored in the current node. For example, if the linked list node contains a number, head.val would be that number.

# (head.val, head): Here, we create a tuple with two elements. The first element is head.val, which is the value of the current node, and the second element is head, which is the entire node itself.

# heapq.heappush(heap, (head.val, head)): Finally, we use the heapq.heappush() function to add this tuple to the heap. The heap is a data structure that maintains its elements in a specific order (min-heap order, where the smallest element is at the top). By using heappush, we ensure that the heap remains in this order, with the smallest head (based on head.val) at the top of the heap



# Continue with the code execution until the min heap is not empty . So : while heap:
# Pop the smallest element (based on its value) from the min heap
#     val, node = heapq.heappop(heap)
#     # Attach the node to the end of the merged list
#     tail.next = node
#     tail = tail.next
#     # Check if there is a next node in the linked list
#     if node.next:
#         # If there is a next node, add it to the min heap
#         heapq.heappush(heap, (node.next.val, node.next))
# # Return the head of the merged list
# return dummy.next

#TC-O(n logk) and SC-O(k))
#---------------------------------------------------------------------
#Other approaches to solve the problem:-
# ---------------
#APPROACH 1:
#Create a vector of nodes
#Put all nodes of LL in that vector, then sort them
#Takw out 1 by 1
#TC- O(nk log nk)
#SC:O(nk)
#------------------
#APPROACH 2:
#Convert into the MERGE TWO SORTED LL problem
#Take any 2 LL
#Merge them
#Then sort them
#Then tale out one by one 
#TC -O(k*k*n)
#SC - O(k)





import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeKLists(self, lists):
        heap = []
        dummy = ListNode(-1)
        tail = dummy

        # Add the heads of all lists to the min heap
        for head in lists:
            if head:
                heapq.heappush(heap, (head.val, head))

        while heap:
            val, node = heapq.heappop(heap)
            tail.next = node
            tail = tail.next

            if node.next:
                heapq.heappush(heap, (node.next.val, node.next))

        return dummy.next

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next



# class Solution(object):
#     def mergeKLists(self, lists):
#         """
#         :type lists: List[ListNode]
#         :rtype: ListNode
#         """