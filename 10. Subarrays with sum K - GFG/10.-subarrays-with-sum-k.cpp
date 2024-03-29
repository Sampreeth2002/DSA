// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int a[], int n, int k)
    {
        
        
        unordered_map<int,int> mp;
        int runningSum = 0;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            runningSum += a[i];
            if(mp.find(runningSum-k)!=mp.end())
            {
                count += mp[runningSum-k];
            }
            if(runningSum==k) count++;
            mp[runningSum]++;
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends