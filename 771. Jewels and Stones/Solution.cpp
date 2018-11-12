class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int j[52]{}, result = 0;
        const char *p = J.c_str();
        while (*p) j[isupper(*p) ? (*p - 'A') : (*p - 'a' + 26)] = 1, ++p;
        p = S.c_str();
        while (*p) result += j[isupper(*p) ? (*p - 'A') : (*p - 'a' + 26)], ++p;
        return result;
    }
};