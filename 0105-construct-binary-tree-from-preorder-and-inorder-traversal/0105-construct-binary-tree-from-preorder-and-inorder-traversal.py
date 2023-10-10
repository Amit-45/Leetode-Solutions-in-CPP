# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        def get_tree(prestart, preend, instart, inend):
            ino_idx = inomap[preorder[prestart]]
            l = ino_idx - instart
            r = inend - ino_idx

            root = TreeNode(preorder[prestart])
            root.left = get_tree(prestart + 1, prestart + l, instart, ino_idx - 1) if l > 0 else None
            root.right = get_tree(prestart + l + 1, preend, ino_idx + 1, inend) if r > 0 else None
            return root

        inomap = {el: i for i, el in enumerate(inorder)}
        return get_tree(0, len(preorder) - 1, 0, len(inorder) - 1)
        