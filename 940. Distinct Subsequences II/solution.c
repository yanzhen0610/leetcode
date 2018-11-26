int distinctSubseqII(char* S) {
    const static int64_t m = 1e9 + 7;
    int64_t end_with[26] = {}, result = 0, last;
    while (*S)
    {
        last = result;
        result = (result * 2 + 1 - end_with[*S - 'a'] + m) % m;
        end_with[*S - 'a'] = (end_with[*S - 'a'] + result - last + m) % m;
        ++S;
    }
    return result;
}