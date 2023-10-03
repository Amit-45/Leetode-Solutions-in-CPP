#ARRAY IMPLEMENTATION of Design Browser History

#Create a class called Browser History 
#Create a constructor withn param (self,str)
#Store the homepage in an array called history : history = [homepage] 
#Take 2 pointers i pointer and len pointer 
#i pointer points to current page. Default value is 0 :  self.i = 0
#len pointer to calculate the true length . Default value is 1: self.len = 1
# We don't calculate length directly from arrray .Why ? We will know later 
#---------------Back---------------------
# Create a function back with param (self,steps)
# We have an array we have to move back "steps" number of steps. We don't have to shift the pointer because with arrays we can just calculate the new position. We know that "i" is our current position.
#We take this "i" and subtract number of steps and we have a new index but the problem is: this could be out of bounds. So we have an  "if" statement so that the value [self.i-steps] is not less than 0. Easy way to do that is take maximum of (self.i,0) it will automatically compare if its value less than zero or greater than zero. Finally, we take that pointer and written the self.history[].

# Only these two lines:
#  self.i = max(self.i - steps, 0)
#  return self.history[self.i]

# Notice moving backwards does not change the length of the array.
# Moving backward does not delete anything.Same for moving forward.

#---------------Forward---------------------
#Copy paste the two lines
#-Minus before steps instead of plus
#-Instead of taking max we take min
#-Also as said before, instead of calculating length, directly from array,I will use length to compare. So I use self.len-1
#Finally use the same return statement 

#Only these two lines:
#  self.i = min(self.i + steps, self.len - 1)
#  return self.history[self.i]

#--------------For visiting(tricky part)-----------------
# -----else part--------------
#While we visit any URL we delete the forward history. If me manually keep on erasing by popping it will be O(n). SO we soft erase them
#First ass the URL to nect position . By next position I mean self.i + 1
#Only possible if position is already filled before
#Otherwise we woulg get index out of bound error 
#So in else part we write: self.history[self.i + 1] = url
#Overall we are trying to update the URL at the current position.
#-------if part ---------------
#Only append the URL if history array is not long enough. Afterwards when we add homepage it will be long enough
#In the visit method, you're indexing self.i + 1 to update the URL at the current position. However, this might result in an "index out of bounds" error if self.i + 1 is greater than or equal to the length of the self.history array.
#To avoid this error, you first need to check whether there's enough space in the self.history array to accommodate the new URL before attempting to update it at self.i + 1. This is why you have the condition if len(self.history) < self.i + 2 in your code.
#Overall This approach ensures that you don't exceed the bounds of the array while updating the history and provides a mechanism for managing forward history.

# So: if len(self.history) < self.i + 2: , self.history.append(url)

#Arrays are 0 based indexing.  When you visit a new page, both self.i and self.len are updated to reflect the new state of the browsing history, ensuring consistency and correctness in managing the history as you navigate through it.

#So: self.i += 1 and self.len = self.i + 1

class BrowserHistory(object):

    def __init__(self, homepage):
        self.i = 0
        self.len = 1
        self.history = [homepage]
        

    def visit(self, url):
        if len(self.history) < self.i + 2:    # If there's not enough space in history, append the URL.
            self.history.append(url)
        else:
            self.history[self.i + 1] = url    # Update the URL at the current position.
        self.i += 1                           # Move the pointer to the new page.
        self.len = self.i + 1                 # Update the true history length.
        

    def back(self, steps):
        self.i = max(self.i - steps, 0)
        return self.history[self.i]
        

    def forward(self, steps):
        self.i = min(self.i + steps, self.len - 1)
        return self.history[self.i]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)