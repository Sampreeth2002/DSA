// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        //code here
        base = (base /2)-1; 
        long long int ans = (base*(base+1))/2;
        // for(long long int i = base;i>=0;i--)
        // {
        //     ans+=i;
        // }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		long long int base;
		cin >> base;

        Solution ob;
		cout << ob.numberOfSquares(base) << "\n";

	}

	return 0;
}
  // } Driver Code Ends