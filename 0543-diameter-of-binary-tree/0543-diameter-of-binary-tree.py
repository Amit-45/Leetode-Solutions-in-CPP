#Bottom up approach -----------------
#Create an auxiliary func: using depth,path we calculate depth,path for upar wala levels
#def f(root):
#def solve(root):
#return f(root)[1] - 1 
#(second arguement -1 because it will give path in no. of nodes.But we need t find no. of edges that is equal to path-1)

#If no root return 0,0:
# if root:
#     return 0,0 (depth,path are both zeroes)

#bring ld and lp form left  ld,lp=f(root.left)
#bring rd and rp from right rd,rp=f(root.right)

#Make the path using this : 
#-First arguement should be the depth : 1+ max(ld,rd)
#-best path for me : max(lp,rp,1+ld+rd)
#Our actual function needs no. of edges:


# class Solution(object):
#     def diameterOfBinaryTree(self, root):
#         def f(root):
#             if root:
#                 ld, Ip = f(root.left)
#                 rd, rp = f(root.right)
#                 return 1 + max(ld, rd), max(rp, 1 + ld + rd)
#             return 0, 0

#         return f(root)[1] - 1
class Solution(object):
    def diameterOfBinaryTree(self, root):
        def f(root):
            if root:
                ld, lp = f(root.left)
                rd, rp = f(root.right)
                return 1 + max(ld, rd), max(lp, rp, 1 + ld + rd)
            else:
                return 0, 0

        return max(f(root)) - 1





# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right