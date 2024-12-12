//TC: O(h)
//MC: O(h), h is the height of the bst

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};
