struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* p = root;

        for (int i = 0; i < word.size(); i++) {
            unordered_map<char, TrieNode*>::iterator iter =
                p->children.find(word[i]);

            if (iter == p->children.end()) {
                p->children[word[i]] = new TrieNode();
            }

            p = p->children[word[i]];
        }

        p->isWord = true;
    }

    bool search(string word) {
        TrieNode* p = root;

        for (int i = 0; i < word.size(); i++) {
            if (p->children.find(word[i]) == p->children.end()) {
                return false;
            }

            p = p->children[word[i]];
        }

        return p->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (p->children.find(prefix[i]) == p->children.end()) {
                return false;
            }

            p = p->children[prefix[i]];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
