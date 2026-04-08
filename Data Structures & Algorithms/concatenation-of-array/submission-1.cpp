class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> Ans;
        for(int i=0;i<nums.size();i++)
        {
            Ans.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            Ans.push_back(nums[i]);
        }
        return Ans;
    }
};