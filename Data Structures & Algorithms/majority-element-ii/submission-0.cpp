class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        unordered_map<int,int> map;
        for(auto num:nums)
            map[num]++;
        for(auto x:map)
        {
            if(x.second>n/3)
            {
                res.push_back(x.first);
            }
        }
        return res;
    }
};