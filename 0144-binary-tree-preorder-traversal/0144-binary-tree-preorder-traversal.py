# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        result = []

        def preorderTraverse(tree):
            if tree is not None:
                result.append(tree.val)
                preorderTraverse(tree.left)
                preorderTraverse(tree.right)

        preorderTraverse(root)
        return result
        