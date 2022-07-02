// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

    map<char,int> createFrequence(string &s)
    {
        map<char,int> mp;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        return mp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<map<char,int>,vector<string>>mp;
       sort(strs.begin(),strs.end());
       int n = strs.size();
       map<char,int> tempMap;
       for(int i=0;i<n;i++)
       {
           tempMap = createFrequence(strs[i]);
           mp[tempMap].push_back(strs[i]);
       }
       
       vector<vector<string>> v;
       for(auto j :mp)
       {
           v.push_back(j.second);
       }
       sort(v.begin(),v.end());
       return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>s(n);
		for(auto &i: s)
			cin >> i;
		Solution obj;
		vector<vector<string>> ans = obj.groupAnagrams(s);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends