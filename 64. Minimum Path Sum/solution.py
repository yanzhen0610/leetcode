class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        last, current = list(grid[0]), list(grid[0])
        for i in range(1, len(last)):
            last[i] += last[i - 1]
        for row in grid[1:]:
            current[0] = row[0] + last[0]
            for j in range(1, len(row)):
                current[j] = min(current[j - 1], last[j]) + row[j]
            last, current = current, last
        return last[-1]
        