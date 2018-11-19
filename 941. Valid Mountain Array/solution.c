bool validMountainArray(int* A, int ASize) {
    if (ASize < 3) return false;
    const int *p = A;
    if (*p++ >= *p) return false;
    for (;(p-A) < ASize; ++p)
        if (*(p-1) >= *p) break;
    if ((p-A) >= ASize)
        return false;
    for (;(p-A) < ASize; ++p)
        if (*(p-1) <= *p)
            return false;
    return true;
}