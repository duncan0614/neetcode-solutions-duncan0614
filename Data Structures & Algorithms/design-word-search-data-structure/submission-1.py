class TrieNode:
    def __init__(self) -> None:
        self.children = {}
        self.endOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for w in word:
            if w not in cur.children:
                cur.children[w] = TrieNode()
            cur = cur.children[w]
        cur.endOfWord = True

    def search(self, word: str) -> bool:
        def dfs(j, root):
            cur = root
            for i in range(j, len(word)):
                w = word[i]
                if w == ".":
                    for c in cur.children.values():
                        if dfs(i + 1, c):
                            return True
                    return False
                else:
                    if w not in cur.children:
                        return False
                    cur = cur.children[w]
            return cur.endOfWord
        return dfs(0, self.root)
