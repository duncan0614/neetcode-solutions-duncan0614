class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool lastChar = false;
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (const auto& c : word) {
            if (cur -> children.find(c) == cur -> children.end()) {
                cur -> children[c] = new TrieNode();
            }
            cur = cur -> children[c];
        }

        cur -> lastChar = true;
        return;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;

        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (const auto& p : cur -> children) {
                    if (dfs(word, i + 1, p.second)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                if (cur -> children.find(c) == cur -> children.end()) {
                    return false;
                }
                cur = cur -> children[c];
            }
        }
        return cur -> lastChar;
    }
};
