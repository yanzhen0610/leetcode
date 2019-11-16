import bisect


class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        minimum = float(next(i for i in range(256) if count[i]))
        maximum = float(next(i for i in range(255, -1, -1) if count[i]))
        mean = sum(index * c
                   for index, c in enumerate(count) if c) / sum(count)
        mode = float(count.index(max(count)))
        sum_of_count = sum(count)
        for i in range(1, 256):
            count[i] += count[i - 1]
        left = bisect.bisect(count, (sum_of_count - 1) // 2)
        right = bisect.bisect(count, sum_of_count // 2)
        median = (left + right) / 2
        return [minimum, maximum, mean, median, mode]
