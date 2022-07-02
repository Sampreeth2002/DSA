// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string s) {
        //code here
        int arr[26]={0};
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
        }
        long long fac[n];
        fac[0] = 1;
        fac[1] = 1;
        for(int i = 2;i<n;i++)
        {
            fac[i] = fac[i-1]*i;
        }
        long long res = 1;
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<s[i]-'a';j++)
            {
                count+=arr[j];
            }
            arr[s[i]-'a']--;
            res+=count*(fac[n-1-i]);
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends