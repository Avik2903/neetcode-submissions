class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
      int nums_size=nums.size();
      for(int i=0;i<nums_size;i++)
      {
        nums.push_back(nums[i]);
      }  
      return nums;
    }
};