#BFS approach Level Order Traversal 
#First take a deque and a res array 
#The deque will have root initially 
#But it is also possibe that the root may have NULL values . So we will handle it later 
#Do till queue is empty  : while q:
#Now lets take a variable rightSide that will store the right side part of each level .Lets initialise it with NULL initially 
#Let me take the queue length. Let's imagine that it is only one level because for level 1 it has only the root element.
#Traverse through elements of the level using a for loop :  for i in range(qLen):
#Pop the element from the left node = q.popleft(). 
#Now add its children to the queue before doing this . Only do this if the node is not NULL if node:
#We assign the right most element of the level to the rightSide : rightSide = node
#Then append the children as said above into the queue : q.append(node.left) and q.append(node.right)
#Now append the result to the right side :   res.append(rightSide.val)
#Also chances are there that this rightSide value is NULL : if rightSide:
#Finally return the result  : return res


class Solution(object):
    def rightSideView(self, root):
        res = []
        q = collections.deque([root])

        while q:
            rightSide = None
            qLen = len(q)

            for i in range(qLen):
                node = q.popleft()
                if node:
                    rightSide = node
                    q.append(node.left)
                    q.append(node.right)
            if rightSide:
                res.append(rightSide.val)
        return res
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right