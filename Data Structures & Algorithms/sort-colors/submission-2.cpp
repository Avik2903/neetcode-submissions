class Solution {
public:
void sort123(vector<int>& nums,int n)
{
    int s=0;
    int mid=0;
    int e=n-1;
    while(mid<=e)
    {
        if(nums[mid]==0)
        swap(nums[mid++],nums[s++]);
        else if(nums[mid]==1)
        mid++;
        else
        swap(nums[mid],nums[e--]);
    }
}
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       sort123(nums,n); 
    }
};