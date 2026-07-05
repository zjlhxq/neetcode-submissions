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
    int maxDepth(TreeNode* r) {
        if (!r) return 0;

        std::queue<TreeNode*> q;
        q.push(r);
        int maxDepth = 0;
        while(!q.empty()) {

            auto qSize = q.size();
            maxDepth ++;
            for(int i=0; i<qSize; i++) {
                auto cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
           
        }

        return maxDepth;
    }
};
