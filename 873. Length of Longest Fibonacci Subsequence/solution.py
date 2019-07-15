class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        number_set, max_n = set(A), 2
        
        for i in range(len(A) - 2):
            for j in range(i + 1, len(A) - 1):
                x, y = A[i], A[j]
                if (max_n - 2) * y > A[-1]:
                    break
                    
                n, z = 2, x + y
                while z in number_set:
                    x, y, z = y, z, y + z
                    n += 1
                max_n = max(max_n, n)
                
        return max_n if max_n != 2 else 0
