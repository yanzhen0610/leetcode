int search(int* nums, int numsSize, int target) {
    int p; // pivot
    int l = 0, r = numsSize - 1, m; // left right middle
    int t;
    
    // find out the pivot
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (nums[m] < nums[r]) r = m;
        else l = m + 1;
    }
    p = l;
    
    l = 0, r = numsSize - 1;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        t = m + p; // rotate
        if (t >= numsSize) t -= numsSize;
        if (nums[t] == target) return t;
        else if (nums[t] < target) l = m + 1;
        else r = m - 1;
    }
    
    return -1;
}