class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int currSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
                currSum += nums[i];
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int index = queries[i][1];
            int val = queries[i][0];
            
            int curr = nums[index];
            if(nums[index]%2==0) currSum -= curr;
            nums[index] += val;
            
            if(nums[index]%2==0)
                currSum+=nums[index];
            
            ans.push_back(currSum);
        }
        
        return ans;
        
    }
};