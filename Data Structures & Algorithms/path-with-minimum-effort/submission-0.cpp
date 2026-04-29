class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
     priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        if(r==n-1 && c==m-1)
            return dis;

        for(int i=0;i<4;i++)
        {
            int newr=r+dx[i];
            int newc=c+dy[i];
            if(newr>=0 &&newr<n && newc>=0 && newc<m)
            {
                int newE=max(abs(heights[r][c]-heights[newr][newc]),dis);
                if(newE<dist[newr][newc])
                {
                    dist[newr][newc]=newE;
                    pq.push({newE,{newr,newc}});
                }
            }
        }
    }
    return 0;   
    }
};