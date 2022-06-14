class Solution {
public:
    
    int fun(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp)
    {
        
        if(j1<0 || j2<0 || j1>=c || j2>=c)
        {
            return -1e8;
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==r-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        
        int maxi = -1e8;
        for(int df1 = -1;df1<=1;df1++)
        {
            for(int df2 = -1;df2<=1;df2++)
            {
                int ans = 0;
                if(j1==j2)
                    ans += grid[i][j1];
                else
                    ans += grid[i][j1] + grid[i][j2];
                ans+=fun(i+1,j1+df1,j2+df2,r,c,grid,dp);
                maxi = max(maxi,ans);
            }
        }
        
        return dp[i][j1][j2] = maxi;
        
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int> (c,-1)));
        
        
        int ans = fun(0,0,c-1,r,c,grid,dp);
        return ans;
    }
};