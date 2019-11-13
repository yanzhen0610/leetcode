# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        nodes, index = [root], 0
        should_ended = False
        while index < len(nodes):
            node = nodes[index]
            index += 1
            if node is None:
                should_ended = True
                continue
            if should_ended:
                return False

            nodes.append(node.left)
            nodes.append(node.right)
        return True