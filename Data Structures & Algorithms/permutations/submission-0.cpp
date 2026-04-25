class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    per(nums,res,0);
    return res;
    }

    void per(vector<int>& nums,vector<vector<int>> &res,int idx)
    {
        if(idx==nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
           swap(nums[i],nums[idx]);
           per(nums,res,idx+1);
           swap(nums[i],nums[idx]);
        }
}
};
