/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int x, y, overlap, max = 0, tmp, result = 0;
        unordered_map<uint64_t, int> m;
        for (auto i = points.begin(); i < points.end(); ++i)
        {
            m.clear();
            overlap = 0; max = 0;
            for (auto j = i + 1; j < points.end(); ++j)
            {
                x = i->x - j->x;
                y = i->y - j->y;
                if (!x and !y)
                {
                    ++overlap;
                    continue;
                }
                tmp = gcd(x, y);
                if (tmp)
                {
                    x /= tmp;
                    y /= tmp;
                }
                tmp = m[((uint64_t) x) << 32 | y] += 1;
                if (tmp > max) max = tmp;
            }
            if ((tmp = max + overlap + 1) > result) result = tmp;
        }
        return result;
    }
private:
    int gcd(int a, int b)
    {
        while (b)
        {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};