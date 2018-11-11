# About

This repo is a backup of my solutions on LeetCode online judge. And the solutions are mainly written in C/C++.

## Make C++ less overhead

In order to reduce the C++ I/O synchronization overhead, please add the following code to the very first line in your solution. The following code will reduce the runtime significantly. (Depending on the problems, it's a significant improve in most problems.)

```C++
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
```

For example, the original solution is like

```C++
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        string result;
        result.reserve(S.length() + 1);
        result[S.length()] = '\0';
        for (int i = S.length() - 1; i >= 0; --i)
        {
            sum = (sum + shifts[i]) % 26;
            result[i] = (S[i] - 'a' + sum) % 26 + 'a';
        }
        return result;
    }
};
```

then add the code to the very first line

```C++
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        string result;
        result.reserve(S.length() + 1);
        result[S.length()] = '\0';
        for (int i = S.length() - 1; i >= 0; --i)
        {
            sum = (sum + shifts[i]) % 26;
            result[i] = (S[i] - 'a' + sum) % 26 + 'a';
        }
        return result;
    }
};
```

The I/O synchronization is the main problem that makes C++ slower than most of others languages.
