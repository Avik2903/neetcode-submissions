class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
    void mergesort(vector<int>& nums,int l,int r)
    {
        if(l>=r) return;
        int m=(l+r)/2;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums,l,m,r);
    }
    void merge(vector<int>& nums,int l,int m,int r)
    {
        vector<int> temp;
        int i=l;
        int j=m+1;
        while(i<=m && j<=r)
        {
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=m)
            temp.push_back(nums[i++]);
        while(j<=r)
            temp.push_back(nums[j++]);
        for(int i=l;i<=r;i++)
            nums[i]=temp[i-l];
    }
};