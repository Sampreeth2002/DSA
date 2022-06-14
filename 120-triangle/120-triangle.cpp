class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        
        for(int i=0;i<n;i++)
        {
            prev[i] = triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                curr[j] = min(triangle[i][j] + prev[j+1],triangle[i][j] + prev[j]);
            }
            prev=curr;
        }
        
        return prev[0];
        
        
    }
};