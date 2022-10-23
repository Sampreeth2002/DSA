class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        int repeatedNumber = -1;
        for(int i=0;i<n;i++)
        {
            int val = nums[i];
            val = abs(val);
            val--;
            if(nums[val]<0)
            {
                val++;
                repeatedNumber = val;
            }
            else
            {
                nums[val] = nums[val]*-1;
            }
        }
        
        int missiedVal = -1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                missiedVal = i+1;
                break;
            }
        }
        
        vector<int> v = {repeatedNumber,missiedVal};
        return v;
        
    }
};