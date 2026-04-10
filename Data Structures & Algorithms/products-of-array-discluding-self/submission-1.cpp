class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int ans=1;int idx=-1;int zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                idx=i;
                zero++;
            }
            else{
                ans*=nums[i];
            }
        }
    vector<int> res(n, 0);
    if (zero == 0) {
        for (int i = 0; i < n; i++)
            res[i] = ans / nums[i];
    }
    // If one zero, set product only at the zero's index
    else if (zero == 1)
        res[idx] = ans;

        return res;
    }
};
