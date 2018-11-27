// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1, m;
    while (l < n)
    {
        m = l + (n - l) / 2;
        if (isBadVersion(m)) n = m;
        else l = m + 1;
    }
    return n;
}