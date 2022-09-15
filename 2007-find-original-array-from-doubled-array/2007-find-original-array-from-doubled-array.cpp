class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n%2==1)
            return ans;
        
        map<int,int> mp;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(changed[i]!=0)
                mp[changed[i]]++;
            else
                c++;
        }
        if(c%2!=0)
        {
            return ans;
        }
        else
        {
            c = c/2;
            while(c--)
                ans.push_back(0);
        }
        
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            int num = it->first;
            int freq = it->second;
            // cout<<num<<" ";
            if(freq>0)
            {
                if(mp.find(num*2)==mp.end())
                {
                    ans.clear();
                    // cout<<"********";
                    return ans;
                }
                else
                {
                    mp[num] = 0;
                    int secondFrequence = mp[num*2];
                    if(secondFrequence>0)
                    {
                        if(freq<=secondFrequence)
                        {
                            while(freq--)
                            {
                                ans.push_back(num);
                                mp[num*2]--;
                            }
                                
                        }
                        else
                        {
                            ans.clear();
                            return ans;
                        }
                    }
                    else
                    {
                        ans.clear();
                        return ans;
                    }
                }   
            }
            
        }
        
        return ans;
    }
};