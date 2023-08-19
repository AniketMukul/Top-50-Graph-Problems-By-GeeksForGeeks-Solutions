class Solution {
  public:
    int delrow[4]={-1,0,+1,0};
    int delcol[4]={0,+1,0,-1};
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        int answer;
        vector<vector<int>>visited(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,pair<int,int>>>q;
        visited[0][0]=1;
        q.push({{0,0},{k,0}});
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int walls=q.front().second.first;
            int steps=q.front().second.second;
            q.pop();
            if(row==n-1 && col==m-1)
            {
                return steps;
            }
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]<walls)
                {
                    if(mat[nrow][ncol]==0)
                    {
                        visited[nrow][ncol]=walls;
                        q.push({{nrow,ncol},{walls,steps+1}});
                    }
                    else if(mat[nrow][ncol]==1 && visited[nrow][ncol]<walls && walls>0)
                    {
                        visited[nrow][ncol]=walls-1;
                        q.push({{nrow,ncol},{walls-1,steps+1}});
                    }
                }
            }
        }
        return -1;
    }
};
