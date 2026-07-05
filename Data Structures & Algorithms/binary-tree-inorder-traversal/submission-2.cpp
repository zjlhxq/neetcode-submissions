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
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris traversal
        auto curr = root;
        vector<int> res;
        while(curr) {
            if(!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {

                auto pre = curr->left;
                while (pre->right && pre->right != curr) {
                    pre = pre->right;
                }

                if(!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else if( pre->right == curr) {
                    pre->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }

            }

        }

        return res;

    }
};