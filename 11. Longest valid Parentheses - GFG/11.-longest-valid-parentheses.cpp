// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        stack<int> st;
        int n = S.size();
        st.push(-1);
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='(')
            {
                st.push(i);
            }
            else if(S[i]==')')
            {
                // if(!st.empty() && st.top()=='(')
                // {
                //     st.pop();
                //     maxi = max(maxi,i-st.top());
                // }   
                st.pop();
                if(st.size()==0)
                {
                    st.push(i);
                }
                else
                {
                    maxi = max(maxi,i-st.top());
                }
                
            }
        }
        
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends