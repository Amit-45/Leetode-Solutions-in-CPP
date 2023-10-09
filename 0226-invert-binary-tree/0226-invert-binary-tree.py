#-------Recursive DFS to invert the binary tree

#Given a root node 
#take its children, swap its position
#Now recursively call it for the left and the right sub tree 

#Base case: if tree is empty we don't do the inversion. So return None
#Then swap the children (left and right of root) by #swap
#Then recursively call the ib=nvert function for the left and the right sub tree 
#Finally return the root of the sub tree 

class Solution(object):
    def invertTree(self, root):
        if not root:
            return None
        #swap 
        tmp=root.left
        root.left=root.right
        root.right=tmp

        #recursive call
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

        