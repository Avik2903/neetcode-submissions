class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

    for (const auto& edge : trust) {
        if (edge.size() == 2) {
            int u = edge[0];
            int v = edge[1];
            outdegree[u]++;
            indegree[v]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (outdegree[i] == 0 && indegree[i] == n - 1) {
            return i;
        }
    }
    return -1;
    }
};