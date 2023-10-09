#Recursive DFS for finding the symmetric tree-------------------------------------
#Create another function called dfs tht will do the depth first search (Outer function only carries 2 params)
#Base case : If both the left and right sub trees are found to be NULL, then it is symmetric by default. So return true :
#  if not left and not right, return True
#Base case : If only one of the node is NULL, then it is not a symmetric tree . SO return false 
#if not left or not right, return False
#If non of the base case satisfies then, the tree has both left and right child 
#Compare the values of LC of node and RC of node. Both needs to be equal  : left.val==right.val and 
#Not only that we have to compare the sub trees using DFS: dfs(left.left, right.right)
#Then we have to compare the inner sub trees : dfs(left.right, right.left))
#Now if the first condition is false then the whole statement may become false. in order to solve that we will return as a boolean by wrapping under a return 
#At last call the dfs for the whole tree: return dfs(root.left, root.right)
#MISTAKE I DID: if,if return under one line
#

class Solution(object):
    def isSymmetric(self, root):
        def dfs(left,right):
            if not left and not right:
                return True
            if not left or not right:
                    return False
            return(left.val==right.val and
                    dfs(left.left, right.right) and
                    dfs(left.right, right.left))
        return dfs(root.left, root.right)



# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right    