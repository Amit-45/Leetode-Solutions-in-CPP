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



# class Solution:
#     def maxDepth(self, root):
#         if not root:
#             return 0
        
#         level = 0
#         q = deque([root])
        
#         while q:
            
#             level_size = len(q)  
            
#             for i in range(level_size):
#                 node = q.popleft()
                
#                 if node.left:
#                     q.append(node.left)
                
#                 if node.right:
#                     q.append(node.right)
#             level += 1 
#         return level


# Iterative DFS/ pre order traversal for finding max depth of binary tree------------------------------------
#Base case : Tree empty return 0 bacause the max depth of a empty tree is 0
#Take a stack with initial value of root but remember we also have a depth too .So we take a pair of values.
#stack = [[root, 1]]
#We will do the DFS till the stack is empty : while stack:
#Now we pop from stack 
#We pop 2 values . Remember we have to pop up the pair.So to pop up the pair we can use : node, depth = stack.pop()
#It is possible that the node can be Null do use this condition :   if node:
#If it is not null then, we update our result .For that first let the result be 1 because we have a default depth of 1 : res = 1 
#Then we update our max depth or result by max function : res = max(res, depth)
#Then to our stack we add the chidren of the code we are currently at 
#For that I use the stack.append([node.left,node.right ])
#Acually we have to also append the depth also for each of the children .We can do that to both l and r by  : 
#stack.append([node.left, depth + 1]) and stack.append([node.right, depth + 1])
#At last when stack becomes empty return the result 
class Solution:
    def maxDepth(self, root) :
        if not root:
            return 0
        stack = [[root, 1]]
        res = 1

        while stack:
            node, depth = stack.pop()

            if node:
                res = max(res, depth)
                stack.append([node.left, depth + 1])
                stack.append([node.right, depth + 1])

        return res


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right