// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int dp[1001][1001];
  int lcs(string A,string B,int m,int n)
  {
      for(int i=0;i<=m;i++)
      {
          for(int j =0;j<=n;j++)
          {
              if(i==0||j==0)
                dp[i][j] = 0;
          }
      }
      
      for(int i=1;i<=m;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(A[i-1]==B[j-1])
              {
                    dp[i][j]=1+dp[i-1][j-1];
              }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
          }
      }
      
      return dp[m][n];
  }
  
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(A.begin(),A.end());
        // string A
        int m = A.size();
        int dp[m+1][m+1];
        int ans = lcs(A,B,m,m);
        return ans;
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends