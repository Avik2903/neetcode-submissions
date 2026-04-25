class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> comb;
            for (int bit = 0; bit < n; ++bit) {
                if (mask & (1 << bit)) {
                    comb.push_back(bit + 1);
                }
            }
            if (comb.size() == k) {
                res.push_back(comb);
            }
        }
        return res;
    }
};