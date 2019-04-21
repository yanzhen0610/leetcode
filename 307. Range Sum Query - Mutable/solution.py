class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.n = len(nums)
        self.tree = [0]*self.n + nums
        for i in range(self.n-1, 0, -1):
            self.tree[i] = self.tree[i*2] + self.tree[i*2+1]
        

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: None
        """
        i += self.n
        self.tree[i] = val
        while i > 0:
            left, right = (i-1, i) if i&1 else (i, i+1)
            self.tree[i//2] = self.tree[left] + self.tree[right]
            i //= 2
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        i, j, s = i+self.n, j+self.n, 0
        print('aaa')
        while i <= j:
            if i&1:
                print('i', self.tree[i])
                s += self.tree[i]
                i += 1
            if j&1 == 0:
                print('j', self.tree[j])
                s += self.tree[j]
                j -= 1
            i //= 2
            j //= 2
        return s


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)