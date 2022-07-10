// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxh.size()==0)
        {
            maxh.push(x);
        }
        else if(maxh.size()!=minh.size())
        {
            minh.push(x);
        }
        else 
           maxh.push(x);
       if(minh.size()&&maxh.size())
           balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxh.size()==minh.size())
        {
            if(minh.top()<maxh.top())
            {
                int temp = minh.top();
                minh.pop();
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(temp);
            }
        }
        else
        {
            if(minh.top()<maxh.top())
            {
                int temp = minh.top();
                minh.pop();
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(temp);
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans;
       if(minh.size()==0 || maxh.size()!=minh.size()) 
       {
           ans=double(maxh.top());
           return ans;
       }
       else
       {
           double a = double(minh.top());
           double b = double(maxh.top());
           ans = (a+b)/2;
           return ans;
       }
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends