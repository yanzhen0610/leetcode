struct {
    bool operator()(string a, string b)
    {
        return strcmp(a.c_str() + a.find(' '), b.c_str() + b.find(' ')) < 0;
    }
} cmp;

bool only_digit(const string& s)
{
    return isdigit(*(s.c_str() + s.find(' ') + 1));
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        for (const auto& log : logs) if (!only_digit(log)) result.push_back(log);
        sort(result.begin(), result.end(), cmp);
        for (const auto& log : logs) if (only_digit(log)) result.push_back(log);
        return result;
    }
};