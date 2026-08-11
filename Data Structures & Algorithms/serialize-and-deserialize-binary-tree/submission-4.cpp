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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output = "";
        serialize(root, output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        return deserialize(ss);
        
    }
private:
    TreeNode* deserialize(stringstream& ss) {
        string token;
        
        if (!getline(ss, token, ',')) {
            return nullptr;
        }
        
        if(token == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserialize(ss);
        root->right = deserialize(ss);

        return root;

    }

    void serialize(TreeNode* root, string& s) {
        if(root == nullptr) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serialize(root->left, s);
        serialize(root->right, s);
    }


};
