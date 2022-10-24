class Solution {
public:
    
    
    string finalAns = "";
    void fun(int index,vector<string>& arr,string ans)
    {
        //Base Condition
        int nm = arr.size();
        if(index==nm)
        {
            if(finalAns.size()<ans.size())
            {
                finalAns = ans;
            }
            return;
        }
        
        int n = ans.size();
        string str = arr[index];
        int m = str.size();
        int check = 0;
        int sameCharCheck = 0;
        
        string test = str;
        sort(test.begin(),test.end());
        
        for(int i=0;i<m-1;i++)
        {
            if(test[i]==test[i+1])
            {
                sameCharCheck = 1;
                break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[j]==ans[i])
                {
                    check = 1;
                    break;
                }
            }
            if(check) break;
        }
        
        if(check||sameCharCheck)
        {
            fun(index+1,arr,ans);
        }
        else
        {
            fun(index+1,arr,ans+str);
            fun(index+1,arr,ans);   
        }
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            fun(i,arr,ans);
        }
        int kk = finalAns.size();
        return kk;
    }
};