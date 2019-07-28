

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* a, int length, int* return_length)
{
    int* p = (int*) malloc(sizeof(int) * length);
    int i = 0, j = length - 1, index = length - 1;
    *return_length = length;
    
    while (i <= j)
        if (abs(a[i]) > abs(a[j]))
            p[index--] = a[i] * a[i++];
        else
            p[index--] = a[j] * a[j--];
    
    return p;
}


