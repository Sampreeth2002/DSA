// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==1)
            return "1";
        else if(n==2)
            return "11";
        
        string result = lookandsay(n-1);
        int count = 1;
        string newResult = "";
        for(int i=1;i<result.size();i++)
        {
            if(result[i]!=result[i-1])
            {
                newResult += '0' + count;
                newResult += result[i-1];
                count = 1;
            }
            else
            {
                count++;
            }
            if(i==result.size()-1)
            {
                newResult += '0' + count;
                newResult += result[i];                
            }
        }
        
        return newResult;
    }   
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends