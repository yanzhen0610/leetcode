class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        string result;
        result.reserve(S.length() + 1);
        result[S.length()] = '\0';
        for (int i = S.length() - 1; i >= 0; --i)
        {
            sum = (sum + shifts[i]) % 26;
            result[i] = (S[i] - 'a' + sum) % 26 + 'a';
        }
        return result;
    }
};