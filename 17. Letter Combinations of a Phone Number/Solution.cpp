class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        function<void(const string&, const char*)> recursion =
            [&result, &recursion](const string& prefix, const char* p)
        {
            if (*p)
            {
                const char* letter = num_pad[*p - '0'];
                while (*letter) recursion(prefix + *letter++, p + 1);
            }
            else if (!prefix.empty()) result.push_back(prefix);
        };
        recursion("", digits.c_str());
        return result;
    }
private:
    static const char* const num_pad[];
};

const char* const Solution::num_pad[] = {
    " ",
    "*",    "abc",  "def",
    "ghi",  "jkl",  "mno",
    "pqrs", "tuv",  "wxyz",
};
