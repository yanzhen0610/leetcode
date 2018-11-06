class Solution {
public:
    bool isNumber(string s) {
        const char *p = s.c_str(), *q;
        
        // trim left
        while (std::isspace(*p)) ++p;
        if (*p == '+' || *p == '-') ++p;
        q = p;
        
        while (std::isdigit(*p)) ++p;
        if (*p == '.')
        {
            // no digit(s)
            if (p == q && !std::isdigit(*(p + 1))) return false;
            ++p;
            while (std::isdigit(*p)) ++p;
        }
        
        if (*p == 'e')
        {
            // no number before e
            if (p++ == q) return false;
            if (*p == '+' || *p == '-') ++p;
            // no digit after e
            if (!std::isdigit(*p)) return false;
            ++p;
            while (std::isdigit(*p)) ++p;
        }
        
        // trim right
        while (std::isspace(*p)) ++p;
        
        // not empty and read to the end
        return p != q && *p == 0;
    }
};