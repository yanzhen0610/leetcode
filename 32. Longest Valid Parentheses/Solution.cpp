class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        vector<int> dp(s.size(), -1);
        int current = 0, result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') stack.push_back(i);
            else if (!stack.empty()) dp[i] = stack.back(), stack.pop_back();
        }
        for (int i = dp.size() - 1; i >= 0; --i)
        {
            if (dp[i] == -1) current = 0;
            else
            {
                current += i - dp[i] + 1;
                i = dp[i];
                if (current > result) result = current;
            }
        }
        return result;
    }
};