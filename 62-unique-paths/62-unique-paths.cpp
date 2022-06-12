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
        vector<int> prev (n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                curr[j]=1;
                continue;
            }
                int up = 0;
                int down = 0;
                if(i>0)
                {
                    up = prev[j];
                }
                if(j>0)
                {
                    down = curr[j-1]; 
                }
                curr[j] = up+down;
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
};