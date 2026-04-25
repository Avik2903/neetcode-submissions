struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.addWord(word);
        }

        unordered_map<int, vector<string>> cache;
        return backtrack(0, s, trie, cache);
    }

private:
    vector<string> backtrack(int index, string& s, Trie& trie, unordered_map<int, vector<string>>& cache) {
        if (index == s.size()) {
            return {""};
        }

        if (cache.count(index)) {
            return cache[index];
        }

        vector<string> res;
        TrieNode* curr = trie.root;

        for (int i = index; i < s.size(); ++i) {
            char c = s[i];
            if (!curr->children.count(c)) {
                break;
            }
            curr = curr->children[c];
            if (curr->isWord) {
                for (const string& suffix : backtrack(i + 1, s, trie, cache)) {
                    if (!suffix.empty()) {
                        res.push_back(s.substr(index, i - index + 1) + " " + suffix);
                    } else {
                        res.push_back(s.substr(index, i - index + 1));
                    }
                }
            }
        }

        return cache[index] = res;
    }
};