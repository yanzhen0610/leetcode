class Solution {
// private:
//     static const string nstr;
//     static const string pstr;
public:
    int myAtoi(string str) {
        auto it = str.cbegin();
        bool neg = false;
        // int result = 0, tmp;
        long long result = 0;
        
        while (isspace(*it)) ++it;
        if (*it == '+') { ++it; }
        else if (*it == '-') { ++it; neg = true; }
        while (*it == '0') ++it;
        auto start = it;
        
        while (isdigit(*it) && (it - start <= 10)) ++it;
        // while (isdigit(*it) && (it - start <= 11)) ++it;
        if (it == start) return 0;
        
        // if ((it - start) >= 10)
        // {
        //     /**
        //      * This statement here is use to compare
        //      * if the value of the string is larger
        //      * then the limit of the int. It's not
        //      * necessary, but it did speedup a little
        //      * bit due to the instruction level.
        //      * 
        //      * `long long` is 64bits and the CPU
        //      * arithmetic instruction implementations
        //      * may take longer time to execute than
        //      * 32bits `int` and also the
        //      * multiplication instruction.
        //      * 
        //      * Due to the optimization of the CPU
        //      * instructions and compliers, I'm not 100%
        //      * sure about this, so this approach is
        //      * just "probably" quicker a little bit.
        //      */
        //     if (neg)
        //     {
        //         if ((it - start) > 10) return INT_MIN;
        //         for (int i = 0; i < 10; ++i)
        //         {
        //             tmp = *(start + i) - nstr[i];
        //             if (tmp > 0) return INT_MIN;
        //             else if (tmp < 0) break;
        //         }
        //         if (tmp == 0) return INT_MIN;
        //     }
        //     else
        //     {
        //         if ((it - start) > 10) return INT_MAX;
        //         for (int i = 0; i < 10; ++i)
        //         {
        //             tmp = *(start + i) - pstr[i];
        //             if (tmp > 0) return INT_MAX;
        //             else if (tmp < 0) break;
        //         }
        //         if (tmp == 0) return INT_MAX;
        //     }
        // }
        
        while (start != it)
        {
            result = result * 10 + (*start - '0');
            ++start;
        }
        if (neg) result = -result;
        
        if (result > INT_MAX) return INT_MAX;
        else if (result < INT_MIN) return INT_MIN;
        
        // if (neg) return -result;
        return result;
    }
};
// const string Solution::nstr = "2147483648";
// const string Solution::pstr = "2147483647";