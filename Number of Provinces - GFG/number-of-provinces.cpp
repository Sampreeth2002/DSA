//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void bfs(vector<int> &visited,queue<int> &q,int start_node,vector<vector<int>> adj)
    {
        q.push(start_node);
        visited[start_node] = 1;
        while(!q.empty())
        {
            
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                
                if(adj[node][i]!=0 && i!=node)
                {
                    // if(node==2)
                    // {
                    //     cout<<i<<" ";
                    // }
                    if(!visited[i])
                    {
                        q.push(i);
                        visited[i] = 1;
                    }
                        
                }
            }
        }
        return;
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V+1,0);
        int count = 0;
        queue<int> q;
        int start = 0;
        for(int i=0;i<V;i++)
        {
            // count++;
            
            if(!visited[i])
            {
                // cout<<i<<" ";
                count++;
                bfs(visited,q,i,adj);
            }
        }
        // cout<<endl;
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends