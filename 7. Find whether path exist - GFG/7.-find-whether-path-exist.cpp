// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    bool check(vector<vector<int>>& grid,int x,int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        // int c = 0;
        if(grid[x][y]==0) return false;
        if(grid[x][y]==2) return true;
        grid[x][y] = 0;
        if(x+1<n)
            {
                if(check(grid,x+1,y)) return true;
                // c=1;
            }
            if(x-1>=0)
            {
                if(check(grid,x-1,y)) return true;
                // c=1;
            }
            if(y+1<m)
            {
                if(check(grid,x,y+1)) return true;
                // c=1;
            }
            if(y-1>=0)
            {
                if(check(grid,x,y-1)) return true;
                // c=1;
            }
            
            return false;
        
        
        
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        int x = -1;
        int y = -1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    x = i;
                    y = j;
                }
            }
        }
         return check(grid,x,y);
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends