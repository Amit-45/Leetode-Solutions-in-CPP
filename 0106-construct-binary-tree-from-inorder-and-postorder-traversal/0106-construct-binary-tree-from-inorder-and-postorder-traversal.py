# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        def get_tree(instart, inend, poststart, postend):
            if instart > inend or poststart > postend:
                return None

            root_val = postorder[postend]
            root = TreeNode(root_val)

            ino_idx = inomap[root_val]
            left_length = ino_idx - instart

            root.left = get_tree(instart, ino_idx - 1, poststart, poststart + left_length - 1)
            root.right = get_tree(ino_idx + 1, inend, poststart + left_length, postend - 1)

            return root

        inomap = {el: i for i, el in enumerate(inorder)}
        return get_tree(0, len(inorder) - 1, 0, len(postorder) - 1)

        