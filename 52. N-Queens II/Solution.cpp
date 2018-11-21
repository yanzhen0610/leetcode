class Solution {
public:
    Solution() : diagonal1(new bool[32] + 16), diagonal2(new bool[32] + 16), column(new bool[32] + 16)
    {
        for (int i = -16; i < 16; ++i)
            diagonal1[i] = false, diagonal2[i] = false, column[i] = false;
    }
    ~Solution() { delete[] (diagonal1 - 16), (diagonal2 - 16), (column - 16); }
    int totalNQueens(int n) { return nq(0, n); }
private:
    int nq(int row, int n)
    {
        if (row >= n) return 1;
        int count = 0;
        int d1, d2;
        for (int i = 0; i < n; ++i)
        {
            if (column[i]) continue;
            d1 = row - i, d2 = row + i;
            if (diagonal1[d1]) continue;
            if (diagonal2[d2]) continue;
            
            column[i] = true;
            diagonal1[d1] = true;
            diagonal2[d2] = true;
            
            count += nq(row + 1, n);
            
            column[i] = false;
            diagonal1[d1] = false;
            diagonal2[d2] = false;
        }
        return count;
    }
    bool* const diagonal1;
    bool* const diagonal2;
    bool* const column;
};