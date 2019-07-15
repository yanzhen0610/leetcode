class Solution:
    cache = {0: 0, 1: 1}
    def fib(self, N: int) -> int:
        if N not in Solution.cache:
            Solution.cache[N] = self.fib(N - 1) + self.fib(N - 2)
        return Solution.cache[N]

