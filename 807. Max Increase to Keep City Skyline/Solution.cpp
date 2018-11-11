class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(grid.size()), col(grid.size());
        int i, j, tmp, result = 0;
        for (i = 0; i < grid.size(); ++i)
        {
            for (j = 0; j < grid.size(); ++j)
            {
                tmp = grid[i][j];
                if (tmp > row[i]) row[i] = tmp;
                if (tmp > col[j]) col[j] = tmp;
            }
        }
        for (i = 0; i < grid.size(); ++i)
            for (j = 0; j < grid.size(); ++j)
                result += min(row[i], col[j]) - grid[i][j];
        return result;
    }
};