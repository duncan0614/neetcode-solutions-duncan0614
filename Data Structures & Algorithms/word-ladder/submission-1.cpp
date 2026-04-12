class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end() || beginWord == endWord) return 0;
        int ret = 0;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            ret++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                string node = q.front();
                q.pop();
                if (node == endWord) return ret;
                for (int j = 0; j < node.length(); j++) {
                    char org = node[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == org) continue;
                        node[j] = c;
                        if (words.find(node) != words.end()) {
                            q.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = org;
                }
            }
        }
        return 0;
    }
};
