// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

struct node
	{
	    int u;
	    int v;
	    int wt;
	    node(int first,int second,int third)
	    {
	        u = first;
	        v = second;
	        wt = third;
	    }
	};


class Solution{
	public:
	
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> distance(V, 1e8);
        
        distance[S] = 0;
        
        for(int i=0; i<V-1; i++){
            for(vector<int> edge : adj){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                distance[v] = min(distance[v], distance[u]+w);
            }
        }
        
        return distance;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends