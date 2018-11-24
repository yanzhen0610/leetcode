class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int word_s = 0, word_e;
        const char* p = str.c_str();
        unordered_map<char, string> m;
        unordered_map<string, char> rm;
        for (auto c : pattern)
        {
            for (word_e = word_s; p[word_e] and p[word_e] != ' '; ++word_e);
            if (word_e == word_s) return false;
            string word = str.substr(word_s, word_e - word_s);
            word_s = word_e;
            if (p[word_s]) ++word_s;
            if (m.find(c) == m.end()) m[c] = word;
            else if (m[c] != word) return false;
            if (rm.find(word) == rm.end()) rm[word] = c;
            else if (rm[word] != c) return false;
        }
        return word_s >= str.size();
    }
};