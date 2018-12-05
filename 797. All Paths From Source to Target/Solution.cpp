class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> v(graph.size(), false);
        vector<int> p;
        vector<vector<int>> result;
        r(graph, result, v, p, 0);
        return result;
    }
    void r(vector<vector<int>>& g, vector<vector<int>>& result, vector<bool> v, vector<int> p, int node)
    {
        v[node] = true;
        p.push_back(node);
        if (node == g.size() - 1) result.push_back(p);
        else for (auto n : g[node]) if (!v[n]) r(g, result, v, p, n);
    }
};