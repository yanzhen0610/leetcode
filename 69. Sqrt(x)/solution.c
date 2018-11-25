int mySqrt(int x) {
    int64_t l = 0, r = 1 << 16, m, t;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (((t = m * m) <= x) && ((m + 1) * (m + 1) > x)) return m;
        else if (t < x) l = m + 1;
        else r = m - 1;
    }
    return x;
}