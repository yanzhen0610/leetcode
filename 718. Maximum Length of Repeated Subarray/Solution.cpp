class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> m(B.size() + 1);
        int i, j, result = 0;
        for (i = 0; i < A.size(); ++i)
        {
            vector<int> n(B.size() + 1);
            for (j = 0; j < B.size(); ++j)
            {
                if (A[i] == B[j])
                {
                    n[j + 1] = m[j] + 1;
                    result = max(result, n[j + 1]);
                }
            }
            swap(m, n);
        }
        return result;
    }
};