# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        order = []
        def inOrderTrav(curr):
            if not curr:
                return
            # visit left
            inOrderTrav(curr.left)
            # visit curr
            order.append(curr.val)
            # visit right
            inOrderTrav(curr.right)

        inOrderTrav(root)
        last = order[0]
        for i in range(1,len(order)):
            if order[i] <= last:
                return False
            last = order[i]
        return True

