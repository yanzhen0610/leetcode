class Solution:
    def minCostClimbingStairs(self, costs: List[int]) -> int:
        x, y = 0, 0
        for cost in costs:
            x, y = y, min(x, y) + cost
        return min(x, y)
