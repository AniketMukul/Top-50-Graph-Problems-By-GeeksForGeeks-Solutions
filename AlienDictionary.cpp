class Solution{
    public:
    vector<int> solve(int n,vector<vector<int>>&adj)
    {
        vector<int>indigree(n,0);
        queue<int>q;
        vector<int>topo_sort;
        for(int i=0;i<n;i++)
        {
            for(int it:adj[i])
            {
                indigree[it]++;;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indigree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo_sort.push_back(node);
            for(int it:adj[node])
            {
                indigree[it]--;
                if(indigree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return topo_sort;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        string answer="";
        vector<vector<int>>adj(K);
        vector<int>toposort;
        for(int i=0;i<N-1;i++)
        {
            string s=dict[i];
            string t=dict[i+1];
            int len=min(s.length(),t.length());
            for(int i=0;i<len;i++)
            {
                if(s[i]!=t[i])
                {
                    adj[s[i]-'a'].push_back(t[i]-'a');
                    break;
                }
            }
        }
        toposort=solve(K,adj);
        for(int it:toposort)
        {
            answer=answer+char(it+'a');
        }
        return answer;
    }
};
