class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev (n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                
                if(obstacleGrid[i][j]) curr[j] = 0;
                
                else if(i==0 && j==0){
                curr[j]=1;
                continue;
            }
                else
                {
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
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
};