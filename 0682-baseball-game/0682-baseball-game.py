#Take an empty stack 
#Go through every single op in input array 
#Write the 3 if statements for '+', 'D', 'c' and finally if non of above then it is an 'integer' for the variable op
#Now for each fulfill what is given in question and at last append except for case "C" where we need to pop()
#If we have '+' : sum of two prev scores by using :stack[-1] in python (that returns the last value of the stack .In other languages we can use s[lenght()-1])
#If we have 'D' : double the prev value
#If we have 'C' : pop the last value

#(IMPORTANT: It is not given that for every case the prev elements exist or such thing .So take care of that condition also)


class Solution(object):
    def calPoints(self, operations):
        stack =[]
        for op in operations:
            if op == "+" and len(stack)>=2 :
                stack.append(stack[-1]+ stack[-2])
            elif op == "D" and len(stack)>=1:
                stack.append(2 * stack[-1])
            elif op == "C" and len(stack)>=1:
               stack.pop()
            else:
                stack.append(int(op))
        return sum(stack)



        