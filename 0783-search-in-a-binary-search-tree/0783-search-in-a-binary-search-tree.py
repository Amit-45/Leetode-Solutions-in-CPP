#We are given with root node and also the value to be searched
#I will first take a current pointer pointing to root node
#Then we apply a loop which will search the given key 
#If root node is the key we simply return the we will simply return the whole subtree connected to the root node : return curr
#If the curr value is greater than the value to be searched go to the left subtree
#If the curr value is smaller than the value to be searched so to the right sub tree
#If all the condition fails return the curr itself 
class Solution:
    def searchBST(self, root, val):
        curr = root
        while curr:
            if curr.val == val:
                return curr
            elif curr.val > val:
                curr = curr.left
            else:
                curr = curr.right
        return curr

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right







        