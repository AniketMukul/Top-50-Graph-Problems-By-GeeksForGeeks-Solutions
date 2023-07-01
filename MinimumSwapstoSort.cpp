class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int answer=0;
	    vector<pair<int,int>>adj;
	    vector<bool>visited(nums.size(),false);
	    for(int i=0;i<nums.size();i++)
	    {
	        adj.push_back({nums[i],i});
	    }
	    sort(adj.begin(),adj.end());
	    for(int j=0;j<nums.size();j++)
	    {
	        if(visited[j] || adj[j].second==j)  
	        {
	            continue;
	        }
	        int k=j;
	        int count=0;
	        while(!visited[k])
	        {
	            visited[k]=true;
	            k=adj[k].second;
	            count=count+1;
	        }
	        answer=answer+(count-1);
	    }
	    return answer;
	}
};
