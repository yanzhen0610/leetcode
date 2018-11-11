int compareVersion(char* v1, char* v2) {
    char *p1 = v1, *p2 = v2;
    long long t1, t2;
    while (*p1 || *p2)
    {
        while (*v1 == '0') ++v1;
        while (*v2 == '0') ++v2;
        while (*p1 != '.' && *p1) ++p1;
        while (*p2 != '.' && *p2) ++p2;
        t1 = p1 - v1, t2 = p2 - v2;
        if (t1 > t2) return 1;
        if (t1 < t2) return -1;
        if (t1)
            while (v1 < p1)
            {
                t1 = *v1 - *v2;
                if (t1 > 0) return 1;
                if (t1 < 0) return -1;
                ++v1, ++v2;
            }
        if (*p1) ++p1;
        if (*p2) ++p2;
        v1 = p1, v2 = p2;
    }
    return 0;
}