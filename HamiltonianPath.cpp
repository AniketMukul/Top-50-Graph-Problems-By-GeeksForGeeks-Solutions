class Solution
{
    public:
    bool solve(int node,vector<vector<int>>&adj,int N,int count,vector<int>&visited)
    {   
        visited[node]=1;
        if(count==N)
        {
            return true;
        }
        for(int it:adj[node])
        {
            if(!visited[it])
            {
                if(solve(it,adj,N,count+1,visited))
                {
                    return true;
                }
            }
        }
        visited[node]=0;
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>>adj(N+1);
        for(int i=0;i<Edges.size();i++)
        {
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        vector<int>visited(N+1,0);
        for(int i=1;i<=N;i++)
        {
            if(solve(i,adj,N,1,visited))
            {
                return true;
            }
        }
        return false;
    }
};
