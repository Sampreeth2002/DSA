//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool findIsCycle(int node,vector<int> &vis,vector<int> adj[])
  {
      vis[node] = 1;
      queue<pair<int,int>> q;
      q.push({node,-1});
      while(!q.empty())
      {
          int n = q.size();
          for(int i=0;i<n;i++)
          {
              int t1 = q.front().first;
              int parent = q.front().second;
              q.pop();
              for(auto it:adj[t1])
              {
                  if(it==parent) continue;
                  if(vis[it]==1) return true;
                  else
                  {
                      q.push({it,t1});
                      vis[it] = 1;
                  }
              }
          }
      }
      return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0);
        // queue<int> q;
        vis[0] = 1;
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(findIsCycle(i, vis, adj)) return true; 
            }
        }
        return false; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends