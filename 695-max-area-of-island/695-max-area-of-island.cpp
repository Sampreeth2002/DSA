class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0||i>n-1||j<0||j>m-1||grid[i][j]==0)
            return 0; 
        
        grid[i][j] = 0;
        int count = 1;
        
        count+=dfs(grid,i+1,j);
        count+=dfs(grid,i-1,j);
        count+=dfs(grid,i,j-1);
        count+=dfs(grid,i,j+1);
        
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int colums = grid[0].size();
        int count = 0;
        int maxi = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<colums;j++)
            {
                if(grid[i][j]==1)
                {
                    int val = dfs(grid,i,j);
                    maxi = max(maxi,val);
                }
            }
        }
        
        return maxi;
    }
};