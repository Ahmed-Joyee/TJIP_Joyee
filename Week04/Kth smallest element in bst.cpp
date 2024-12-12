//TC: O(n)
//MC: O(n), n is the no of nodes in bst

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        tmp[0] = k;
        dfs(root, tmp);
        return tmp[1];
    }

    void dfs(TreeNode* node, vector<int>& tmp) {
        if (!node) return;
        dfs(node->left, tmp);
        tmp[0]--;
        if (tmp[0] == 0) {
            tmp[1] = node->val;
            return;
        }
        dfs(node->right, tmp);
    }
};
