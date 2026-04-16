class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;int j=n-1;
        while(j>=i)
        {
            int m= i+((j-i)/2);
            if(nums[m]==target)
                return m;
            else if(nums[m]>target)
            {
                n=m;
                j=m-1;
            }
            else
                i=m+1;
        }
        return n;
    }
};