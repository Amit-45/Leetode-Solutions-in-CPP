#First define the two stacks : 1st(normal stack) and 2nd(min stack). Do it using self. because it is constructor
#First operation [push]: Append the value to 1st stack using append.
#Meanwhile compare the top element of min stack with  value "val". Update the val according to which is minimum.There may be case that minStack in empty. At that time take the min as val only. 
#Whatever the new min is simply append at minStack after calculation
#Second operation [pop]: You need to pop from both the minStack and normal stack
#Third operation [top]: You need to print top of the normal stack
#Fourth opeartion[getMin]: You need to print top of minStack

class MinStack(object):

    def __init__(self):
        self.stack = []
        self.minStack = []
        

    def push(self, val):
       self.stack.append(val)
       val = min(val, self.minStack[-1] if self.minStack else val)
       #val wil be min(top of min stack, val) if non empty 
       #val will be min(only val) if empty
       self.minStack.append(val)

    def pop(self):
        self.minStack.pop()
        self.stack.pop() 

    def top(self):
       return self.stack[-1]
        

    def getMin(self):
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()