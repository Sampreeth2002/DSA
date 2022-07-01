// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int pre(char c)
    {
        if(c=='^') return 3;
        if(c=='/'||c=='*') return 2;
        if(c=='+'||c=='-') return 1;
        return -1;
    }
    
    
    string infixToPostfix(string s) {
       
       s ='(' + s + ')';
       int si = s.size();
       string str = "";
       stack<int> st;
       for(int i=0;i<si;i++)
       {
           if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                    str+=s[i];
           else if(s[i]=='(')
           {
               st.push('(');
           }
           else if(s[i]==')')
           {
               while(!st.empty() && st.top()!='(')
               {
                   str += st.top();
                   st.pop();
               }
               
               if(!st.empty())
               {
                   st.pop();
               }
           }
           else
           {
               while(!st.empty() && pre(st.top())>=pre(s[i]))
               {
                   str+=st.top();
                   st.pop();
               }
               st.push(s[i]);
           }
       }
       
       return str;
       
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends