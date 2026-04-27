class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i=0;i<=n;i++)
        {
           int ans=hammingWeight(i);
            res.push_back(ans);
        }
        return res;
    }
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};

