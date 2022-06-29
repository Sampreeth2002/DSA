// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k==1) return "";
        string str;
        stack<pair<char,int>> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else
            {
                if(st.top().first == s[i])
                {
                    st.push({s[i],st.top().second + 1});
                    int x = k;
                    if(st.top().second == k)
                    {
                        while(x!=0)
                        {
                            st.pop();
                            x--;
                        }
                    }
                }
                else
                {
                    st.push({s[i],1});
                }
            }
        }
        
        while(!st.empty())
        {
            str += st.top().first;
            st.pop();
        }
        
        reverse(str.begin(),str.end());
        return str;
        
        
        
        
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends