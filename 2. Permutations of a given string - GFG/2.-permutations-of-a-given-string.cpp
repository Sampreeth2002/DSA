// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string S,int index,set<string> &ans)
	    {
	        if(S.size()==index)
	        {
	            ans.insert(S);
	            return;
	        }
	        for(int i=index;i<S.size();i++)
	        {
	            swap(S[index],S[i]);
	            solve(S,index+1,ans);
	            swap(S[index],S[i]);
	        }
	    }
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    vector<string> ans1;
		    solve(S,0,ans);
		    for(auto i: ans)
		    {
		        ans1.push_back(i);
		    }
		    return ans1;
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends