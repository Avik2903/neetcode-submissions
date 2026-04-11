class Solution {
public:
    bool isPalindrome(string s) {
       int n=s.size();
       string a;
       for(int i=0;i<n;i++)
       {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            a=a+s[i];
       } 
       string re= a;
        reverse(re.begin(),re.end());
        for(int i=0;i<a.size();i++)
        {
            a[i]=tolower(a[i]);
            re[i]=tolower(re[i]);
        }
       for(int i=0;i<a.size();i++)
       {
            if(a[i]!=re[i])
                return false;
       }
       return true;
    }
};
