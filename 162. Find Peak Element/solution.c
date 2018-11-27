int findPeakElement(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1, m1, m2;
    while (l < r)
    {
        m2 = 1 + (m1 = l + (r - l) / 2);
        if (nums[m1] < nums[m2]) l = m2;
        else r = m1;
    }
    return l;
}