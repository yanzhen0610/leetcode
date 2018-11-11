class Solution {
public:
    string generalize_pattern(string str)
    {
        map<char, char> m;
        char ch = 'a';
        for (auto& c : str)
        {
            if (m.find(c) == m.end()) m[c] = ch++;
            c = m[c];
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