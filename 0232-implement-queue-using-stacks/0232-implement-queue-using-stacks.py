#Create two stacks s1 and s2 : self.s1 = []  and self.s2 = []
#------Push---------------------Pushes element x to the back of the queue.------
#If stack 1 is empty append the element : self.s1.append(x)
#If stack 1 is not empty , pop the element that was present in s1 and append it to s2 :      
#    while self.s1: self.s2.append(self.s1.pop())
#If stack 2 is not empty , pop the element that was present in s1 and append it to s1 :           
#    while self.s2: self.s1.append(self.s2.pop())
# -----Pop ---------------Removes the element from the front of the queue and returns it-------
#return self.s1.pop()
#------Peek --------------Returns the element at the front of the queue.------------
#return self.s1[-1]
#-----Emoty---------------Returns true if the queue is empty, false otherwise.---------
#return not self.s1


class MyQueue(object):
    def __init__(self):
        self.s1 = []  
        self.s2 = []

    def push(self, x):
        while self.s1:
            self.s2.append(self.s1.pop())
        self.s1.append(x)
        while self.s2:
            self.s1.append(self.s2.pop())

    def pop(self):
        return self.s1.pop()

    def peek(self):
        return self.s1[-1]

    def empty(self):
        return not self.s1

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
