class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<int> tmp;
        vector<vector<int>> result;
        for (auto& a : A)
        {
            for (auto it = a.crbegin(); it < a.crend(); ++it)
                tmp.push_back(*it ^ 1);
            result.push_back(tmp);
            tmp.clear();
        }
        return result;
    }
};