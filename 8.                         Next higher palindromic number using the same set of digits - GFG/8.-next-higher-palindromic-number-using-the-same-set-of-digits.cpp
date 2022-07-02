// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  string nextPermutation(string s)
  {
      int n = s.size();
        int ind, ind2;
        for(ind=n-2;ind>=0;ind--){
            if(s[ind]<s[ind+1]) //getting first break point
               break; 
        }
        
        if(ind<0){ // array sorted in reverse order
            reverse(s.begin(),s.end());
            return s;
        }
        else{ // find second break point
            for(ind2=n-1;ind2>ind;ind2--)
                if(s[ind2]>s[ind])
                    break;
            swap(s[ind],s[ind2]);
            reverse(s.begin()+ind+1,s.end());//reverse from first break point
        }
        return s;
  }
  
  
    string nextPalin(string s) { 
        //complete the function here
        string ans ="";
        int n= s.size();
        for(int i=0;i<n/2;i++)
        {
            ans+=s[i];
        }
        ans = nextPermutation(ans);
        string temp = ans;
        reverse(temp.begin(),temp.end());
        if(n%2!=0)
        {
            ans+=s[n/2];
        }
        ans+=temp;
        if(ans>s)
        {
            return ans;
        }
        return "-1";
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends