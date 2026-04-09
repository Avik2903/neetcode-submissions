class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count; 
        // count frequency of each number

        for(int n: nums) count[n]++; 
        // build frequency map

        vector<vector<int>> bucket(nums.size()+1); 
        // bucket[i] = numbers that appear i times

        for(auto& e: count) 
            bucket[e.second].push_back(e.first); 
        // place each number in its frequency bucket

        vector<int> res; 
        // result array

        for(int i = bucket.size()-1; i > 0; --i){ 
            // start from highest frequency
            for(int n : bucket[i]){
                res.push_back(n); 
                // add number to result
                if(res.size() == k) return res; 
                // stop when we have k elements
            }
        }
        return res;
    }
};