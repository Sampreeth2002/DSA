//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m  = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                q.push({i,0});
            
            if(grid[i][m-1]==1)
                q.push({i,m-1});
        }
        
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
                q.push({0,j});
            
            if(grid[n-1][j]==1)
                q.push({n-1,j});
        }
        
        while(q.empty()==false)
        {
            int row = q.front().first;
            int col = q.front().second;
            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, 1, 0, -1}; 
            q.pop();
            grid[row][col] = 0;
            for(int i=0;i<4;i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = 0;
                }
            }
            
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans++;
                }
            }
            // cout<<endl;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends