class Solution {
public:
    int findMin(vector<int> &nums) {
        //see we will try to find the element in thsi 
        int n=nums.size();
        int low=0,high=n-1;
        while(low < high){
            int mid=low+(high-low)/2;
            if(nums[mid] > nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};
