//TC: O(n)
//MC: O(n)

class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    void insert(int num) {
        TrieNode* cur = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!cur->children[bit]) {
                cur->children[bit] = new TrieNode();
            }
            cur = cur->children[bit];
        }
    }

    int findMaxXOR(int num) {
        TrieNode* cur = this;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (cur->children[oppositeBit]) {
                maxXOR |= (1 << i);
                cur = cur->children[oppositeBit];
            } else {
                cur = cur->children[bit];
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            root->insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, root->findMaxXOR(num));
        }
        return maxResult;
    }
};
