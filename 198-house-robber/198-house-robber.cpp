class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr, prev1,prev2;
        prev2  = nums[0];
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)
                pick+=prev1;
            int notPick = prev2;
            curr = max(pick,notPick);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};