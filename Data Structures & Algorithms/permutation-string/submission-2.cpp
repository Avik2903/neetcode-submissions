class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
        {
            return false;
        }
        vector<int>v(26,0);
        int i=0;
        for(int i=0;i<s1.size();i++)
        {   
            v[s1[i]-'a']++;
        }
        int tot_char=s1.size();
        int j=0;
        while(j<s2.size())
        {
            if(v[s2[j]-'a']>0)
            {
               tot_char--; 
               
            }
            v[s2[j]-'a']--;
                j++;
            if(tot_char==0)
            {
                return true;
            }

        if (j - i == s1.size()) {
            if (v[s2[i] - 'a'] >= 0)
                tot_char++;

            v[s2[i] - 'a']++;
            i++;
        }
        }
        return false;
    }
};
