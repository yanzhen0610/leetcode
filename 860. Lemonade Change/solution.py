class Solution(object):
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        five, ten = 0, 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                five, ten = five - 1, ten + 1
            elif bill == 20:
                if ten > 0:
                    five, ten = five - 1, ten - 1
                else:
                    five -= 3
            if five < 0:
                return False
        return True
        