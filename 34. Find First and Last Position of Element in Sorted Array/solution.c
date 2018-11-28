/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int l = 0, r = numsSize - 1, m;
    int *result = malloc(sizeof(int) * 2);
    result[0] = result[1] = -1;
    *returnSize = 2;
    
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (nums[m] < target) l = m + 1;
        else r = m;
    }
    if (nums[l] != target) return result;
    result[0] = l;
    
    r = numsSize - 1;
    while (l < r)
    {
        m = l + (r - l) / 2 + 1;
        if (target < nums[m]) r = m - 1;
        else l = m;
    }
    result[1] = r;
    
    return result;
}