#DOUBLY LINKED LIST IMPLEMENTATION
#WE are using DLL because we have to move forward as well as backward
#Visiting will be O(1)(because it doesn't matter, we are at beginning or the end. New page will always be next node after the current node)
#However backword or forward in this is O(n) because from a to c we can't directly go. We have to traverse all elements in between. So O(n)

#-------class ListNode-------------------
#Add next,prev (default value is NULL)
#Add val (which is URL)
# -------class Browser History-----------
#init constructor:-
#Create a constructor with param(self,homepage)
#Create a current pointer to point to the page we are currently at.
#Then create a ListNode and pass homepage that will be default page
#Meanwhile prev and next are set to NULL by default(we had set before)
#----Visit -------------------------------
#Create a constructor visit and pass the parameter(self,url)
#Then we create a listNode and pass the URL
# We know that we are at current page and currentpage is homepage (that we had passed in __init__). So current page cannot be NULL
#Now we will set the links between curr and the new ListNode created
#First connection(->)   : self.cur.next = ListNode(url,.....)
#Second connection(<-)  : self.cur.next = ListNode(url, self.curr)
#As the current and last node, Move the current pointer to the newly visited page : self.cur = self.cur.next
#------Back---------------------------------
# - Use while loop (as we used in getValues at very begg)
# While self.curr and steps >0 steps-=1 (same as always)
# - Also increment the curr (In this case we move backwards) . SO self.curr = self.curr.prev
#-To stop as soon as we reach last node change the "self.curr" to "self.curr.prev"
#-At last return self.curr.val
#------Forward------------------------------
#Same as back operation
#Difference:-
# -Insetead of looking at prev node, we will look at next node
#In while loop change "self.curr.prev" to "self.curr.next"
#Instead of moving back we move forward
#Change "delf.curr.prev" to "self.curr.next"

class ListNode:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

class BrowserHistory:
    def __init__(self, homepage):
        self.cur = ListNode(homepage)

    # O(1)
    def visit(self, url):
        self.cur.next = ListNode(url, self.cur)
        self.cur = self.cur.next

    # O(n)
    def back(self, steps):
        while self.cur.prev and steps > 0:
            self.cur = self.cur.prev
            steps -= 1
        return self.cur.val

    # O(n)
    def forward(self, steps):
        while self.cur.next and steps > 0:
            self.cur = self.cur.next
            steps -= 1
        return self.cur.val