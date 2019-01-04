bool validPalindrome(char* s) {
    bool skipped = false;
    char *p = s, *q = s + strlen(s) - 1;
    while (p < q)
    {
        if (*p != *q)
        {
            if (skipped) return false;
            if (*(p + 1) == *q && ((p + 2 > q - 1) || (*(p + 2) == *(q - 1)))) ++p, skipped = true;
            else if (*p == *(q - 1) && ((p + 1 > q - 2) || (*(p + 1) == *(q - 2)))) --q, skipped = true;
            else return false;
        }
        ++p, --q;
    }
    return true;
}