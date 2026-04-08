class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> mp,mp1;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            mp1[t[i]]++;
        }
        for(auto i:mp)
        {
            if(mp1[i.first] != i.second)
                return false;
        }
        return true;
    }
};
