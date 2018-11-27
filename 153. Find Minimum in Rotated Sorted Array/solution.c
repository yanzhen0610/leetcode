int findMin(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1, m;
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (nums[m] < nums[r]) r = m;
        else l = m + 1;
    }
    return nums[l];
}