/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap_i(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int *p = A, *q = A + ASize - 1;
    while (p < q)
    {
        while (!(*p & 1) && p <= q) ++p;
        while ((*q & 1) && p <= q) --q;
        if (p < q) swap_i(p, q);
    }
    *returnSize = ASize;
    return A;
}