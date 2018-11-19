int minDeletionSize(char** A, int ASize) {
    int result = 0, i, j = 0, len = strlen(*A);
    for (; j < len; ++j)
        for (i = 1; i < ASize; ++i)
            if (A[i-1][j] > A[i][j])
            {
                ++result;
                break;
            }
    return result;
}