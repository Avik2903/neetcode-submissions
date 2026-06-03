class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis=grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==2)
                {
                    q.push({i,j});
                }
                if(vis[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)    return 0;
        if(q.empty())   return -1;
        int min=-1;
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 1) {
                        vis[i][j] = 2;
                        fresh--;
                        q.push({i, j});
                    }
                }
            }
            min++;
        }
        
        if (fresh == 0)
            return min;
        return -1;
    }
};
