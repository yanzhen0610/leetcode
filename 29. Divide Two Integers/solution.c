int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    int sign = (dividend >> 31) ^ (divisor >> 31);
    long long ldividend = labs(dividend), ldivisor = labs(divisor);
    int result = 0, tmp;
    while (ldividend >= ldivisor)
    {
        tmp = 0;
        while (ldividend >= (ldivisor << ++tmp));
        result += 1 << (--tmp);
        ldividend -= ldivisor << tmp;
    }
    return sign ? -result : result;
}