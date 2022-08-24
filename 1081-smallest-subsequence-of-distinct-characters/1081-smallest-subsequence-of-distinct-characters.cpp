class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        unordered_map<char,int> mp;
        for(auto it:s)mp[it]++;
        
        stack<char> st;
        
        unordered_set<char> vis;
        
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            mp[s[i]]--;
            if(vis.find(s[i])!=vis.end())continue;
            else
            {
                while(st.size() and st.top()>=s[i] and mp[st.top()]>0)
                {
                    vis.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                vis.insert(s[i]);
            }
        }
        
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};