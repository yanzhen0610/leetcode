from collections import defaultdict

class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        on_x, on_y, on_lrd, on_rld = defaultdict(int), defaultdict(int), defaultdict(int), defaultdict(int)
        lamps_set = set()
        result = list()

        for x, y in lamps:
            on_x[x] += 1
            on_y[y] += 1
            on_lrd[y - x] += 1
            on_rld[y + x] += 1
            lamps_set.add((x, y))

        for x, y in queries:
            illuminated = 1 if on_y[y] or on_x[x] or on_lrd[y - x] or on_rld[y + x] else 0
            result.append(illuminated)

            if illuminated:
                for x_ in range(x - 1, x + 2):
                    for y_ in range(y - 1, y + 2):
                        if 0 <= y_ < N and 0 <= x_ < N:
                            lamp = x_, y_
                            if lamp in lamps_set:
                                on_y[y_] -= 1
                                on_x[x_] -= 1
                                on_lrd[y_ - x_] -= 1
                                on_rld[y_ + x_] -= 1
                                lamps_set.remove(lamp)

        return result
