class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<uint64_t> s;
        int tmp, min = INT_MAX;
        for (const auto& point : points)
            s.insert( ((uint64_t) point[0]) << 32 | point[1] );
        for (auto i = points.begin(); i < points.end(); ++i)
        {
            for (auto j = i + 1; j < points.end(); ++j)
            {
                tmp = abs(((*i)[0] - (*j)[0]) * ((*i)[1] - (*j)[1]));
                if (!tmp) continue;
                if (s.count( ((uint64_t) (*i)[0]) << 32 | (*j)[1] ) &&
                    s.count( ((uint64_t) (*j)[0]) << 32 | (*i)[1] ) &&
                    tmp < min) min = tmp;
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};