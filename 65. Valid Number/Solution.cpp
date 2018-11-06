class Solution {
public:
    bool isNumber(string s) {
        const char *p = s.c_str(), *q;
        
        while (std::isspace(*p)) ++p;
        if (*p == '+' || *p == '-') ++p;
        q = p;
        
        while (std::isdigit(*p)) ++p;
        if (*p == '.')
        {
            if (p == q && !std::isdigit(*(p + 1))) return false;
            ++p;
            while (std::isdigit(*p)) ++p;
        }
        
        if (*p == 'e')
        {
            if (p++ == q) return false;
            if (*p == '+' || *p == '-') ++p;
            if (!std::isdigit(*p)) return false;
            ++p;
            while (std::isdigit(*p)) ++p;
        }
        
        while (std::isspace(*p)) ++p;
        
        return p != q && *p == 0;
    }
};