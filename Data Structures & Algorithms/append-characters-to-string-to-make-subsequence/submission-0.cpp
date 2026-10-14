class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> store(n, vector<int>(26, n + 1));
        store[n - 1][s[n - 1] - 'a'] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            store[i] = store[i + 1];
            store[i][s[i] - 'a'] = i;
        }

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (store[i][t[j] - 'a'] == n + 1) {
                break;
            }
            i = store[i][t[j] - 'a'] + 1;
            j++;
        }

        return m - j;
    }
};