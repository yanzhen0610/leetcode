class Solution {
public:
    int myAtoi(string str) {
        auto it = str.c_str();
        bool neg = false;
        long long result = 0;
        
        while (isspace(*it)) ++it;
        if (*it == '+') { ++it; }
        else if (*it == '-') { ++it; neg = true; }
        while (*it == '0') ++it;
        auto start = it;
        
        while (isdigit(*it) && (it - start <= 10)) ++it;
        if (it == start) return 0;
        
        while (start != it)
        {
            result = result * 10 + (*start - '0');
            ++start;
        }

        if (neg)
        {
            result = -result;
            if (result < INT_MIN) return INT_MIN;
        }
        else if (result > INT_MAX) return INT_MAX;
        
        return result;
    }
};