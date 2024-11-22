//TC: O(n) for each function call where n is the length of the string
//MC: O(t) where t is the total number of TrieNodes created in the Trie

class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        } 
        endOfWord = false;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
