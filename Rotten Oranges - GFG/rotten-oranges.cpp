//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        
        queue<pair<int,int>> q;
        int perfectOranges = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j] = 2;
                }
                else
                {
                    if(grid[i][j]==1)
                    {
                        perfectOranges++;
                    }
                    vis[i][j] = 0;
                }
                
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int sum = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int noOfOranges = 0;
        int flag = 0;
        while(!q.empty())
        {
            int n1 = q.size();
            flag = 0;
            // if(sum==1) cout<<n1;
            for(int i=0;i<n1;i++)
            {
                int i1 = q.front().first;
                int j1 = q.front().second;
                q.pop();
                // vis[i1][j1] = 2;
                for(int j=0;j<4;j++)
                {
                    int nrow = i1 + drow[j];
                    int ncol = j1 + dcol[j];
                    
                    if(nrow <n && nrow >=0 && ncol <m && ncol >=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                    {
                        if(flag==0)
                        {
                            sum++;
                            flag = 1;
                        }
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                        noOfOranges++;
                    }
                }
            }
        }
        
        if(noOfOranges==perfectOranges) return sum;
        return -1;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends