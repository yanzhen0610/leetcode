class Solution {
public:
    string generalize_pattern(string str)
    {
        char ch = 'a', t, m[26]{};
        for (auto& c : str)
        {
            t = c - 'a';
            if (!m[t]) m[t] = ch++;
            c = m[t];
        }
        return str;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        pattern = generalize_pattern(pattern);
        for (const auto& str : words)
            if (generalize_pattern(str) == pattern)
                result.push_back(str);
        return result;
    }
};