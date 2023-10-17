#Recursive solution for Inorder Traversal  DFS
#Given the root of Binary Tree
#We have to first create a nested function because we have to build the result 
#Then the base case :if the root does not exit 
#Then the function 
# class Solution(object):
#     def inorderTraversal(self, root):
#         res = []
#         def inorder(root):
#             if not root:
#                 return
#             inorder(root.left)
#             res.append(root.val)
#             inorder(root.right)
#         inorder(root)
#         return res


#Iterative solution
#Create a stack 
#Curr pointer initially points to root
#We continue till my current pointer is not Null and The stack is also not empty 
#Go left as long as I can, add it to the stack: while cur : stack.append(cur)
#Move the current pointer down to the left: curr = curr.left 
#One the above while loop exists that means curr is pointing to Null
#First we will pop from the stack stack.pop()
#  the current pointer must be pointing to this curr=stack.pop()
# Add it to our result 
#After appending the result, we shift to the right cur.right
#After going to right, then again we will run our inorder traversal 
#Finally return the result 

class Solution(object):
    def inorderTraversal(self, root):
        # Iterative
        res, stack = [], []
        cur = root

        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            res.append(cur.val)
            cur = cur.right
        return res

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

        