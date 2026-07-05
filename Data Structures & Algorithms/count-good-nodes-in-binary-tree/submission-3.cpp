/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int max_val, int & res) {
        if (!root) return;

        int next_max = max_val;
        if(root->val >= max_val) {
            next_max = root->val;
            res ++;
        }

        dfs(root->left, next_max, res);
        dfs(root->right, next_max, res);
    }
};
