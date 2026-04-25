class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    vector<int> sub;
    subs(0,nums,sub,res);
    return res;
    }
private:
    void subs(int idx,vector<int>& nums,vector<int>& sub,vector<vector<int>>& res)
{
    res.push_back(sub);
    for(int i=idx;i<nums.size();i++)
    {
        if(i>idx && nums[i]==nums[i-1]) continue;
        sub.push_back(nums[i]);
        subs(i+1,nums,sub,res);
        sub.pop_back();
    }
}
};
