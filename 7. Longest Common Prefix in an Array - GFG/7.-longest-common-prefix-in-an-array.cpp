// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        string mini = arr[0];
        for(int i=0;i<n;i++)
        {
            if(mini.size()>arr[i].size())
            {
                mini = arr[i];
            }
        }
        int c = 0;
        bool flag=true;
        for(int i=0;i<mini.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j][i]!=mini[i])
                {
                    flag = false;
                }
            }
            if(!flag) break;
            c++;
        }
        if(c==0) return "-1";
        return mini.substr(0,c);
        
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends