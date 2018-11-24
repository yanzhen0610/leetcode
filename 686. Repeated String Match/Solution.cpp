class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int f = B.find(A);
        if (f == -1)
            if (A.find(B) != -1) return 1;
            else if ((A + A).find(B) != -1) return 2;
            else return -1;
        const char* b = B.c_str() + f;
        while (*b)
            for (auto c : A)
                if (!*b) break;
                else if (*b++ != c) return -1;
        return (B.size() - f) / A.size() + ((B.size() - f) % A.size() ? 1 : 0) + (f ? 1 : 0);
    }
};