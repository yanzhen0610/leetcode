class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto first = nums.begin(), last = nums.end();
        if (first == last) return;
        auto i = last;
        if (first == --i) return;
        
        while (true)
        {
            auto i1 = i;
            
            if (*--i < *i1)
            {
                auto i2 = last;
                while (!(*i < *--i2));
                std::iter_swap(i, i2);
                std::reverse(i1, last);
                return;
            }
            if (i == first)
            {
                std::reverse(first, last);
                return;
            }
        }
    }
};