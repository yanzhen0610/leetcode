class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        stack.reserve(pushed.size());
        int i = 0, j = 0;
        while (i < pushed.size())
        {
            stack.push_back(pushed[i++]);
            while (!stack.empty() && stack.back() == popped[j])
            {
                stack.pop_back();
                ++j;
            }
        }
        return stack.empty();
    }
};