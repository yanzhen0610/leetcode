# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = list()
        r(root, 0, result)
        return result
      
    
def r(node, level, result):
    if node is None:
        return
    if len(result) <= level:
        result.append(node.val)
    else:
        result[level] = max(result[level], node.val)
    r(node.left, level + 1, result)
    r(node.right, level + 1, result)