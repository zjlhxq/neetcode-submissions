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
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        maxGain(root, max_path_sum);
        return max_path_sum;
    }

    int maxGain(TreeNode* root, int &max_path_sum) {
        if(!root) return 0;


        int left_gain = max(maxGain(root->left, max_path_sum), 0);

        int right_gain = max(maxGain(root->right,max_path_sum),0);

        max_path_sum = max(max_path_sum, left_gain + right_gain + root->val);

        return max(left_gain, right_gain) + root->val;
    }
};
