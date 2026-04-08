class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        for(auto x:map)
        {
            if(x.second>nums.size()/2)
                return x.first;
        }
        return {};
    }
};