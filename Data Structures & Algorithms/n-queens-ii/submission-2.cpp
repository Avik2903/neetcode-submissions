class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        function<void(int,int,int,int)> solve = [&](int row, int cols, int diag1, int diag2) {
            if (row == n) { ans++; return; }
            int avail = ((1<<n)-1) & ~(cols|diag1|diag2);
            while (avail) {
                int bit = avail & (-avail);
                avail -= bit;
                solve(row+1, cols|bit, (diag1|bit)<<1, (diag2|bit)>>1);
            }
        };
        solve(0, 0, 0, 0);
        return ans;
    }
};