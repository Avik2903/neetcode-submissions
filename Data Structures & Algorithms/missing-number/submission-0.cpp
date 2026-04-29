class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int n=nums.size();
     int l=nums[n-1];
     int real=(n*(n+1))/2;
     int sum=0;
     for(int i=0;i<n;i++)
     {
        sum+=nums[i];
     }
     if(sum==real) return 0;
     return real-sum;
    }
};
