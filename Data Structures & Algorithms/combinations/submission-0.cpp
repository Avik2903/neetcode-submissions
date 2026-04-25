class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i=0;i<n;i++)
            arr.push_back(i+1);
        vector<vector<int>> res;
        vector<int> ds;
        subset(0,arr,ds,res,k);
        return res;
    }
    void subset(int i,vector<int> &arr,vector<int> &ds,vector<vector<int>>& res,int k)
{
    if(i>=arr.size())
    {
        if(ds.size()==k)
        {
            res.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[i]);
    subset(i+1,arr,ds,res,k);
    ds.pop_back();
    subset(i+1,arr,ds,res,k);
}
};