/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    *returnSize = strlen(S) + 1;
    int * const result = malloc(sizeof(int) * *returnSize);
    int l = 0, r = *returnSize - 1;
    for (int i = 0; i < *returnSize; ++i)
        result[i] = S[i] == 'I' ? l++ : r--;
    return result;
}