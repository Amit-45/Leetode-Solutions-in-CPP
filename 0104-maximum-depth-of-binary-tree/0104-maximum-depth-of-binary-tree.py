#Recursive solution for finding max depth of binary tree--------------------------------------------------------
#Base case : Tree empty return 0 bacause the max depth of a empty tree is o
#If 1 node and no childern: max of left and right subtree = 0, So return 1+max(left),max(right) = 1
#If 1 node with children : Use resursive dfs for left and right sub tree) 
# class Solution:
#     def maxDepth(self, root):
#         if not root:
#             return 0
#         return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

#Iterative BFS/ level order traversal for finding max depth of binary tree----------------------------------------
#Base case : Tree empty return 0 bacause the max depth of a empty tree is 0
#Maintain level

class Solution:
    def maxDepth(self, root):
        if not root:
            return 0
        
        level = 0
        q = deque([root])
        
        while q:
            level += 1 
            level_size = len(q)  
            
            for i in range(level_size):
                node = q.popleft()
                
                if node.left:
                    q.append(node.left)
                
                if node.right:
                    q.append(node.right)
        
        return level


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right