class Solution {
public:
    int numTrees(int n) {
        int catalan[n+1];
        catalan[0] = 1;
        catalan[1] = 1;
        for(int i=2;i<=n;i++)
        {
            catalan[i] = 0;
            for(int j=0;j<i;j++)
            {
                int left = j;
                int right = i-j-1;
                catalan[i] += catalan[left]*catalan[right];
            }
        }
        
        return catalan[n];
    }
};