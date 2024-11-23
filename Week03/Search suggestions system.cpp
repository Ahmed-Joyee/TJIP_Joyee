//TC: O(L)+O(k)
//MC: O(L)
// L is the total no of characters across all products and k is the no of characters in each search word

class TrieNode {
public:
    TrieNode* children[26];
    vector<string> suggestions;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    void insert(const string& product) {
        TrieNode* cur = this;
        for (char c : product) {
            int index = c - 'a';
            if (!cur->children[index]) {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
            if (cur->suggestions.size() < 3) {
                cur->suggestions.push_back(product);
            }
        }
    }

    vector<string> getSuggestions(const string& prefix) {
        TrieNode* cur = this;
        for (char c : prefix) {
            int index = c - 'a';
            if (!cur->children[index]) {
                return {};
            }
            cur = cur->children[index];
        }
        return cur->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        for (const string& product : products) {
            root->insert(product);
        }

        vector<vector<string>> result;
        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            result.push_back(root->getSuggestions(prefix));
        }
        return result;
    }
};
