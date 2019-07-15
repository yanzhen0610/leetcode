class Solution:
    def climbStairs(self, n: int) -> int:
        x, y = 0, 1
        for _ in range(n - 1):
            x, y = y, x + y
        return x + y
        
