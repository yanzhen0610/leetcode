class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        a = max(A)
        b = min(A)
        k = K * 2
        if abs(a - b) > k:
            return abs(a - b) - k
        else:
            return 0
        