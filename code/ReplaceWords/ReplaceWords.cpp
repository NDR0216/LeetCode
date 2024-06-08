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

    int search(string word) { // return the length of prefix
        TrieNode* p = root;

        for (int i = 0; i < word.size(); i++) {
            if (p->children.find(word[i]) == p->children.end()) {
                return word.size();
            }

            p = p->children[word[i]];

            if (p->isWord) {
                return i + 1;
            }
        }

        return word.size();
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dict;

        for (int i = 0; i < dictionary.size(); i++) {
            dict.insert(dictionary[i]);
        }

        istringstream is(sentence);
        string word;
        getline(is, word, ' ');

        string new_sentence = word.substr(0, dict.search(word));
        while (getline(is, word, ' ')) {
            new_sentence += " " + word.substr(0, dict.search(word));
        }

        return new_sentence;
    }
};
