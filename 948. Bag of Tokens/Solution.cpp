class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int score = 0, result = 0;
        int i = 0, j = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while (i <= j)
        {
            if (tokens[i] <= P)
            {
                P -= tokens[i++], ++score;
                if (result < score) result = score;
            }
            else if (score-- > 0) P += tokens[j--];
            else break;
        }
        return result;
    }
};