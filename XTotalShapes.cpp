class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int delrow[4]={-1,0,+1,0};
    int delcol[4]={0,+1,0,-1};
    void solve(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto it=q.front();
                q.pop();
                for(int index=0;index<4;index++)
                {
                    int nrow=it.first+delrow[index];
                    int ncol=it.second+delcol[index];
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol]=='X')
                    {
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int answer=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='X' && !visited[i][j])
                {
                    answer=answer+1;
                    solve(i,j,grid,visited);
                }
            }
        }
        return answer;
    }
};
