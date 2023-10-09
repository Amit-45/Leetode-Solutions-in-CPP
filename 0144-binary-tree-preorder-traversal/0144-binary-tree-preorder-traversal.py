# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        result = []  # Initialize an empty list to store the result.

        def preorder(node):
            if node:
                result.append(node.val)  # Append the value to the result list.
                preorder(node.left)
                preorder(node.right)

        preorder(root)  # Start the traversal from the root node.
        return result  # Return the result list. 

      