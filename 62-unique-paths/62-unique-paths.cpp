class Solution {
public:
    
    int noOfWays(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0&&j==0)
        {
            return 1;
        }
        if(i<0||j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int leftWay = noOfWays(i-1,j,dp);
        int topWay = noOfWays(i,j-1,dp);
        
        return dp[i][j] = leftWay+topWay;

    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return noOfWays(m-1,n-1,dp);
         // dp[m-1][n-1];
    }
};