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
        queue<pair<TreeNode*, int>> q;

        q.push({root, root->val});
        res ++;
        while(!q.empty()) {
            int q_size = q.size();
            for(int i=0; i<q_size; i++) {
                auto curr = q.front();
                q.pop();

                auto curr_path_max = curr.second;
                auto curr_node = curr.first;
                
                // check the left child
                if(curr_node->left) {
                    if(curr_node->left->val >= curr_path_max) {
                        res ++;
                        q.push({curr_node->left, curr_node->left->val});
                    } else {
                        q.push({curr_node->left, curr.second});
                    }
                }

                // check the right child
                if(curr_node->right) {
                    if(curr_node->right->val >= curr.second) {
                        res ++;
                        q.push({curr_node->right, curr_node->right->val});
                    } else {
                        q.push({curr_node->right, curr.second});
                    }
                } 

            }
        }

        return res;
        
    }
};
