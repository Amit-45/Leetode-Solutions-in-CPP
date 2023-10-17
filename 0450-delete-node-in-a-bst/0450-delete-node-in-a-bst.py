#Recursive solution
#Start with base case if root is NULL
#Find the node to be deleted 
#If we finally found the node that we want to delete:
#Edge cases that is written in notes : If tree does not have a left child -> we return right child
#                                    : If tree does not have a right child -> we return left child 
#
#self.deleteNode(root.right, key) and self.deleteNode(root.left, key)
#Make the above to lines equal to root.right and root.left rspectively because instead of returning root(that is passed in the function) def deleteNode(self, root, key), we have to return root.right and root.left as we returned in the else part             
            #if not root.left:
            #     return root.right
            # elif not root.right:
            #     return root.left
#Thats why we changed the two lines
#Now we will find the minimum from the right sub tree 
#Easiest way to to do that is assign the current pointer to the roor
#Now curr should not stop at NULL and it must stop at a valid position
#For stopping at a valid position we use the conditon : while curr.left: curr.left .
#Befor that as we have to finc the min of RST , curr must be equal to root.right
#Till now doing the above steps allows curr to point to the smallest/minimum value 
#Then we replace the current root value with it : root.val=cur.val
#Then we delete that value : self.deleteNode(root.right, root.val)
#At last return root 
class Solution(object):
    def deleteNode(self, root, key):
        if not root:
            return root
        #Finding the node to be deleted
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            #Find the minimum form the right sub tree 
            cur=root.right
            while cur.left:
                cur=cur.left
            root.val=cur.val
            root.right = self.deleteNode(root.right, root.val)
        return root
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

        