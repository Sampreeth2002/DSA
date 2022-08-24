class Solution {
public:
    string smallestSubsequence(string s) {
                vector<int> last_occurence(26, -1);    
        for(int i=0; i<s.length(); i++) {
            last_occurence[s[i]-'a'] = i;
        }
        
        vector<bool> visited(26, false);
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            if(visited[s[i]-'a']) continue; // if element is already present
            while(!st.empty() && last_occurence[st.top()-'a'] > i /* this element is present ahead */ && st.top() > s[i]) {
                visited[st.top()-'a'] = false;
                st.pop();
            }  
            
            visited[s[i]-'a'] = true;
            st.push(s[i]);
        }
        
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    
    }
};