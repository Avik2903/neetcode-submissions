class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0) return "";
        unordered_map<char,int> countT,window;
        for(int i=0;i<t.size();i++)
            countT[t[i]]++;
        int have=0;
        int need=countT.size();
        pair<int,int> res={-1,-1};
        int reslen=INT_MAX;
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            char c=s[r];
            window[c]++;
            if(window[c]==countT[c] && countT.count(c))
                have++;
            while(have==need)
            {
                if(r-l+1<reslen)
                {
                    reslen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]]<countT[s[l]])
                    have--;
                l++;
            }
        }
        return reslen==INT_MAX?"":s.substr(res.first,reslen);
    }
};
