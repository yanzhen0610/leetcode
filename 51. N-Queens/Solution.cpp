class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        int cb[n]{};
        _nq(cb, 1, n, result);
        return result;
    }
    void _nq(int* cb, int q, int n, vector<vector<string>>& result)
    {
        if (q > n)
        {
            add(n, cb, result);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (!cb[i] && safe(n, q, i, cb))
            {
                cb[i] = q;
                _nq(cb, q + 1, n, result);
                cb[i] = 0;
            }
        }
    }
    bool safe(int n, int q, int i, const int* cb)
    {
        int j, k;
        for (j = q - 1, k = i - 1; j > 0 and k >= 0; --j, --k)
            if (cb[k] == j) return false;
        for (j = q - 1, k = i + 1; j > 0 and k < n; --j, ++k)
            if (cb[k] == j) return false;
        return true;
    }
    void add(int n, const int* cb, vector<vector<string>>& result)
    {
        vector<string> chessboard = make_chessboard(n);
        for (int i = 0; i < n; ++i)
            chessboard[cb[i] - 1][i] = 'Q';
        result.push_back(chessboard);
    }
    vector<string> make_chessboard(int n)
    {
        vector<string> chessboard;
        char dots[n + 1];
        int i;
        for (i = 0; i < n; ++i)
            dots[i] = '.';
        dots[n] = '\0';
        for (i = 0; i < n; ++i)
            chessboard.push_back(dots);
        return chessboard;
    }
};