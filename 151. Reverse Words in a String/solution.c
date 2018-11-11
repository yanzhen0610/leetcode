void swap_c(char* a, char* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void reverse_between_ch(char* p, char* q)
{
    while (p < q) swap_c(p++, q--);
}
void reverseWords(char *s) {
    char *p = s, *q = s;
    
    while (isspace(*q)) ++q;
    while (*q)
    {
        while (!isspace(*q) && *q) *p++ = *q++;
        *p++ = ' ';
        while (isspace(*q)) ++q;
    }
    *(p = --p < s ? s : p) = 0;
    
    reverse_between_ch(s, p - 1);
    p = q = s;
    while (*q)
    {
        while (!isspace(*q) && *q) ++q;
        reverse_between_ch(p, q - 1);
        p = ++q;
    }
}