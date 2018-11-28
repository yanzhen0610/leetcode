double myPow(double x, int n) {
    bool neg = n < 0;
    double result = 1;
    uint32_t p;
    if (neg) p = -n;
    else p = n;
    
    while (p)
    {
        if (p & 1) result *= x;
        x *= x;
        p >>= 1;
    }
    
    return neg ? (1 / result) : result;
}