# Approach : Using 2 queues 
# Step 1: Initialize the first queue
# Step 2: Initialize the second queue
# Step 3: Push the new element onto the second queue
# Step 4: Transfer all elements from the first queue to the second queue
# Step 5: Swap the names of q1 and q2 to make q2 act as the main stack
# Step 6: Pop and return the top element from the main stack (q1)
# Step 7: Return the top element of the main stack (q1)
# Step 8: Check if the main stack (q1) is empty

import Queue 
class MyStack(object):
    def __init__(self):
        self.q1 = Queue.Queue()  
        self.q2 = Queue.Queue()  
    #O(n)
    def push(self, x):
        self.q2.put(x) 

        while not self.q1.empty():
            self.q2.put(self.q1.get())

        self.q1, self.q2 = self.q2, self.q1

    #O(1)
    def pop(self):
        return self.q1.get()  
    #O(1)
    def top(self):
        return self.q1.queue[0]  
    #O(1)
    def empty(self):
        return self.q1.empty() 




# import Queue

# class MyStack:
#     def __init__(self):
#         self.que = Queue.Queue()

#     def push(self, x):
#         self.que.put(x)
#         size = self.que.qsize()
#         for _ in range(size - 1):
#             self.que.put(self.que.get())

#     def pop(self):
#         return self.que.get()

#     def top(self):
#         return self.que.queue[0]

#     def empty(self):
#         return self.que.empty()

