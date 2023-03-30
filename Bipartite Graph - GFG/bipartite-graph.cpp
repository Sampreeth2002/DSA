//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool check(int start, int V, vector<int>adj[], vector<int> &color)
    {
        queue<int> q;
	   // vector<int> color(
	    
	    q.push(start);
	    color[start] = 0;
	    
	    while(q.empty()==false)
	    {
	        int node = q.front();
	        q.pop();
	        int nodeColor = color[node];
	        for(auto it:adj[node])
	        {
	            if(color[it]!=-1)
	            {
	                int adjNodeColor = color[it];
	                if(nodeColor==adjNodeColor) return false;
	            }
	            
	            else
	            {
	                q.push(it);
	                color[it] = !nodeColor;
	            }
	            
	        }
	    }
	    
	    return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1,-1);
	   
	   for(int i=0;i<V;i++)
	   {
	       if(color[i]==-1)
	       {
	           if(check(i,V,adj,color)==false) return false;
	       }
	   }
	   
	   return true;
	    
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends