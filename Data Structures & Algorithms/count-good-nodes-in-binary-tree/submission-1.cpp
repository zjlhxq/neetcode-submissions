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
        if(!root) return 0;

        int res = 0;
        // <node, max_path_node_val_so_far>
        queue<pair<TreeNode*, int>> q;

        q.push({root, root->val});

        while (!q.empty()) {
            auto curr_pair = q.front();
            q.pop();

            auto node = curr_pair.first;
            int max_val = curr_pair.second;

            if(node->val >= max_val) {
                res ++;
            }

            auto next_max = max(max_val, node->val);

            if(node->left) {
                q.push({node->left, next_max});
            }

            if(node->right) {
                q.push({node->right, next_max});
            }

        }
        return res;
        
    }
};
