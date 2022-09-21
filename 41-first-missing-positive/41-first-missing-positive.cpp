class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) nums[i] = 0;
        }
        
        
        for(int i =0;i<n;i++)
        {
            int val = nums[i];
            val = abs(val)-1;
            if(val>=0 && val<n)
            {
                if(nums[val]>0)
                    nums[val] = -1*nums[val];
                else if(nums[val]==0)
                    nums[val] = -1*(n+1);
            }
        }
        
        for(int i=0;i<n;i++)
            if(nums[i]>=0) return i+1;
        return n+1;
    }
};