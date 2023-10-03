#Create a ListNode class. Create a constructor with param (self,val)
# <-[]-> : Then add a next and prev pointer to it
#Do it by: self.val=val,self.prev=None,self.prev=None
#After that create a LinkedList class
#Inside it create a constructor with param (self)
#Inside constructor create 2 nodes : Left and Right dummy node with initial value 0(we take dummy nodes here because we can have starting and ending points even if there are no nodes .basically we are able to handle all the edge cases) :self.left = ListNode(0) , self.right = ListNode(0)
#Then connect these nodes  : self.left.next = self.right, self.right.prev = self.left

#-----------Get ith index value ------------------------------
#Node afer the left dummy node : 0 index of LL
#Node before the right dunmmy node: last index of LL
#When we are given any index, we just wanna return that value.So: 
#-We are goinh to start from 0th node by placing a pointer named "curr"
#-Then we will keep on incrementing the curr till we reach ur desired index(where we have to return the value)
#For that first mention that curr is at 0th index (which is the index after the left dummy node) : curr=self.left.next
#Now use while loop to check two conditions
#Cond 1:Index out of bound (surr should not be NULL)
#Cond 2: Also index>0 is added to the while loop condition because we will visit every node by decrementing the index: while cur and index > 0
#Before that increment curr to its next pos by : curr= curr.next
#Now we might think that we need to directly return curr.val but not directly because first we have to make sure that it has not gone out of bound.
#For that we can use 3 cases:
#Case 1: if curr is not Null : while curr
#Case 2:Also we must use the condition: What if curr ends at the right dummy node. That will be also considered as Out Of Bound . So curr!=self.right
#Case 3:If index is too small that means index does not exist: index == 0
#In all these cases we have to return the current value: return cur.val
#If the condition fails return -1
#-------------Add at head-------------------------------------
# Let the value to be added be "X" 
# For that create a next and prev also 
# Overall : node,next,prev = ListNode(val), self.left.next and self.left
# We will take the pointer that points from left to its next node(->) and then delete it. 
# After deleting ,point it to nex value X : prev.next = node
# Similarly we take the prev pointer of the next node (<-)  and then delete it 
# After deleting point it to the new value X: next.prev = node 
# Then we have to point the next and prev pointers pointing to the node:
# For that we first point node's next ponting to next and node's prev pointing to prev 
# Overall : node.next = next and node.prev = prev

#------------Insert at tail------------------------------------
#Copy paster the heads code
#Differences:
#Next node here is self.right
#Prev node here is self.right.prev

#-----------Add at index----------------------------------------
# Start form 0 index 
# Keep incrementing till I get the correct index to be at 
# For that first mention that curr is at oth index(index after the dummy node) : curr=delf.left.next
# Now what will happen if the curr reaches the right dummy node : "ITS OKAY" because insertion will be done always to the place just before the node that curr is pointing to
# But what will happen if the pointer goes out of the dummy right node ? In that case we cannot insert a node
# So we use a while loop (same as get value while loop)
# The while loop to check conditions
# Cond 1:Index out of bound (surr should not be NULL)
# Cond 2: Also index>0 is added to the while loop condition because we will visit every node by decrementing the index: while cur and index > 0 Also ind-=1
# Now we might think that we need to directly return curr.val but not directly because first we have to make sure that it has not gone out of bound.
# So we need to check the out of bound conditions that are:
# Cond 1:Index out of bound (curr should not be NULL): if curr
# Cond 2:index==0 : if index==0

# Then copy paste the code [from insert at tail code]
# Differences:
# -next node here is curr
# -prev node here us curr.prev

#-----------Delete at index ----------------------------
# It is same as insert at index but at insert at index we were inserting at a node prev to curr pointer node but in this case will delete the node that curr is pointing to 
# Be careful in condition when curr reaches the right dummy node 
# What will happen if curr reaches the node after the right dummy node 
# Obviously we can't delete all that nodes 
#- Copy paste insertAtIndex code
#Differences are:-
#-Add another condition inside while loop which is curr!=self.right (when curr reaches the right dummy node )
#-In this case next node will be curr.next
#-In this case prev node will be curr.prev
#-Also we do not need to create a new node 
# Erase everything after the while loop and make the changes :-
# No need to create "node". Only next and prev are enough
# []->[] ->[]-> []
#     |      |
#    prev  next
# Now simply take prev node's next pointer and change it: prev.next=next
# Then simply take the prev of the next pointer and change it next.prev=prev
class ListNode:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None


class MyLinkedList(object):
    def __init__(self):
        self.left = ListNode(0)
        self.right = ListNode(0)
        self.left.next = self.right
        self.right.prev = self.left

    def get(self, index):
        cur = self.left.next
        while cur and index > 0:
            cur = cur.next
            index -= 1

        if cur and cur != self.right and index == 0:
            return cur.val
        return -1
        
    def addAtHead(self, val):
        node, next, prev = ListNode(val), self.left.next, self.left
        prev.next = node
        next.prev = node
        node.next = next
        node.prev = prev

        

    def addAtTail(self, val):
        node, next, prev = ListNode(val), self.right, self.right.prev #Changes made in next and prev
        prev.next = node
        next.prev = node
        node.next = next
        node.prev = prev
        

    def addAtIndex(self, index, val):
        cur = self.left.next
        while cur and index > 0:
            cur = cur.next
            index -= 1
        
        if cur and index == 0:
            node,next,prev = ListNode(val),cur,cur.prev
            prev.next = node
            next.prev = node
            node.next = next
            node.prev = prev
        

    def deleteAtIndex(self, index):
        cur = self.left.next
        while cur and cur!=self.right and index > 0:
            cur = cur.next
            index -= 1
        
        if cur and cur!= self.right and index == 0:
            next,prev = cur.next,cur.prev
            next.prev = prev
            prev.next=next
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)