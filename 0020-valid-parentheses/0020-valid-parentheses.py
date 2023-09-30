# Create a hashmap to store the mapping of closing and opening brackets.
# Create an empty stack to keep track of opening brackets.
# Iterate through every character in the input string(for loop).
# If the character is not a closing bracket, push it onto the stack and continue till u encounter a closing bracket
# If the character is a closing bracket:
#   - Check if the stack is not empty because we can't pop from an empty stack
#   - Check if the element at the top of the stack matches the opening bracket for the current closing bracket using condition : stack[-1] != Map[c]
#   - If the conditions above are met, pop the top element from the stack.
# After processing all characters, the stack should be empty if the input is valid.



class Solution:
    def isValid(self, s):
        Map = {")": "(", "]": "[", "}": "{"}
        stack = []

        for c in s:
            if c not in Map:
                stack.append(c)
                continue
            if not stack or stack[-1] != Map[c]:
                return False
            stack.pop()

        return not stack
