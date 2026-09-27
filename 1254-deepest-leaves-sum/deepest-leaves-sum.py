# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode | None) -> int:
        
        q = deque([root])

        while q:
            nn = len(q)
            ans = []
            while nn != 0 :
                node = q[0]
                q.popleft()
                ans.append(node.val)

                if node.left :
                    q.append(node.left)
                if node.right :
                    q.append(node.right)
                nn-=1

            if not q:
                return sum(ans)                
        
        return 0


