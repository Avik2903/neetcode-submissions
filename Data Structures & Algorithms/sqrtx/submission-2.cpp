class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long long int lo=1;
        long long int hi=x;
        int res=1;
        while(hi>=lo)
        {
            long long int m= lo+((hi-lo)/2);
            if(m*m<=x)
            {
                res=m;
                lo=m+1;
            }
            else
            {
                hi=m-1;
            }
        }
        return res;
    }
};