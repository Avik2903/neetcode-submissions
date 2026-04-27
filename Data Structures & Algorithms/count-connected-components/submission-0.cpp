class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findupar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
    bool unionbyrank(int u,int v)
    {
         int pu = findupar(u);
        int pv = findupar(v);
        if (pu == pv) {
            return false;
        }
        if (rank[pv] > rank[pu]) {
            swap(pu, pv);
        }
        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res=n;
        for(auto it:edges)
        {
            if(dsu.unionbyrank(it[0],it[1]))
            {
                res--;
            }
        }
        return res;
    }
};
