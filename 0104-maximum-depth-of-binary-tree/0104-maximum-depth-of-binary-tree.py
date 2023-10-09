#Recursive solution 
#Base case : Tree empty return 0 bacause the max depth of a empty tree is o
#If 1 node and no childern: max of left and right subtree = 0, So return 1+max(left),max(right) = 1
#If 1 node with children : Use resursive dfs for left and right sub tree) 
class Solution:
    def maxDepth(self, root):
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right