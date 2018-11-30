bool isPerfectSquare(int num) {
    uint32_t l = 1, r = 1 << 16, m, t, n = num;
    while (l < r)
    {
        m = l + (r - l) / 2;
        t = m * m;
        if (t == n) return true;
        if (t < n) l = m + 1;
        else r = m - 1;
    }
    return l * l == n;
}