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
#Typically BFS includes a queue
#Maintain level : level = 1
#have a queue with staring value the root of the tree:  q = deque([root])
#Initial level is 1 and keep going until queue is empty : while q
#Take a snap shot of length of queue: level_size = len(q)
# Traverse entire level  : for i in range(level_size):
#Add next level once the loop is finished : level += 1  after the for loop ends
#For every node pop left of queue and store in "node":  node = q.popleft()
# and add its children only if the children are not null
#That means atleast one children we are considering through our code :
#                if node.left:
                #     q.append(node.left)
                
                # if node.right:
                #     q.append(node.right)
#So the level will start from 0 instead of 1



class Solution:
    def maxDepth(self, root):
        if not root:
            return 0
        
        level = 0
        q = deque([root])
        
        while q:
            
            level_size = len(q)  
            
            for i in range(level_size):
                node = q.popleft()
                
                if node.left:
                    q.append(node.left)
                
                if node.right:
                    q.append(node.right)
            level += 1 
        return level


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right