class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result(A.size(), false);
        unsigned long long x = 0;
        auto length = A.size();
        for (int i = 0; i < length; ++i)
        {
            x = (x << 1) | A[i];
            if ((x %= 5) == 0) result[i] = true;
        }
        return result;
    }
};
