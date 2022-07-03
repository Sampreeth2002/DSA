// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int low = 0;
        int end = v.size()-1;
        long firstOuccrence = -1;
        while(low<=end)
        {
            int mid = (low+end)/2;
            if(v[mid]==x)
            {
                firstOuccrence = mid;
                end = mid-1;
            }
            else if(v[mid]<x)
            {
                low = mid +1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        // cout<<firstOuccrence<<endl;
        
         low = 0;
         end = v.size()-1;
         long lastOccurance = -1;
        while(low<=end)
        {
            int mid = (low+end)/2;
            if(v[mid]==x)
            {
                lastOccurance = mid;
                low = mid+1;
            }
            else if(v[mid]<x)
            {
                low = mid +1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        pair<int,int> pr= {firstOuccrence,lastOccurance};
        return pr;
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends