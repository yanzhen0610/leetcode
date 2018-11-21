int totalHammingDistance(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    int result = 0, c, i, j;
    for (i = 0; i < 32; ++i)
    {
        c = 0;
        for (j = 0; j < numsSize; ++j)
            if (nums[j] >> i & 1) ++c;
        result += c * (numsSize - c);
    }
    return result;
}