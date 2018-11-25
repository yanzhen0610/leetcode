// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, m, t;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            t = guess(m);
            if (t == 0) return m;
            else if (t == 1) l = m + 1;
            else r = m - 1;
        }
        return n;
    }
};