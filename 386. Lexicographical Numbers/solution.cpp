class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; ++i)
            recursion(result, i, n);
        return result;
    }
    static void recursion(vector<int> &slice, int number, int max)
    {
        if (number > max) return;
        slice.push_back(number);
        number *= 10;
        for (int i = 0; i < 10; ++i)
            recursion(slice, number + i, max);
    }
};
