from typing import Optional
from python.tests.python_deps.data_structures import TreeNode


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        isPathSumAvailable: bool = False
        if root is None:
            return False
        elif (
            (root.left is None) and (root.right is None) and (targetSum - root.val == 0)
        ):
            return True
        targetSum -= root.val
        leftHasPathSum = self.hasPathSum(root.left, targetSum)
        rightHasPathSum = self.hasPathSum(root.right, targetSum)
        isPathSumAvailable = leftHasPathSum or rightHasPathSum

        return isPathSumAvailable
