/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = malloc(sizeof(int) * 2);
    int *p = numbers, *q = numbers + numbersSize - 1, t;
    *returnSize = 2;
    while (p < q)
    {
        t = *p + *q;
        if (t == target)
        {
            result[0] = p - numbers + 1;
            result[1] = q - numbers + 1;
            break;
        }
        else if (t < target) ++p;
        else --q;
    }
    return result;
}