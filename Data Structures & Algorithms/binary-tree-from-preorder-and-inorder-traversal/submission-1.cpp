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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() -1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end, 
                        vector<int>& inorder, int in_start, int in_end) {
        if(pre_start > pre_end) return nullptr;

        int rootVal = preorder[pre_start];
        TreeNode* root = new TreeNode(rootVal);
        int pivot = -1;
        for(int i=in_start; i<=in_end; i++) {
            if(inorder[i] == rootVal) {
                pivot = i;
                break;
            }
        }

        int left_count = pivot - in_start;

        root->left = buildTree(preorder, pre_start + 1, pre_start + left_count, inorder, in_start, pivot - 1 );
        root->right = buildTree(preorder, pre_start + left_count + 1 , pre_end , inorder, pivot + 1, in_end);
        return root;
    }
};
