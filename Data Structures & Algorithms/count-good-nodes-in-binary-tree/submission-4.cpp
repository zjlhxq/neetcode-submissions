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
        
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});

        while(!s.empty()) {
            auto curr_pair = s.top();
            s.pop();

            auto node = curr_pair.first;
            int max_val = curr_pair.second;

            int next_max = max_val;
            if(node->val >= max_val) {
                res ++;
                next_max = node->val;
            }

            if(node->left) s.push({node->left, next_max});
            if(node->right) s.push({node->right, next_max});

        }

        return res;
    }
};
