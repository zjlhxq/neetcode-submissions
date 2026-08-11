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

        vector<string> tokens;
        stringstream ss(data);
        string token = "";
        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int index = 0;
        return deserialize(tokens, index);
        
    }
private:
    TreeNode* deserialize(const vector<string>& tokens, int& index) {
        if (index >= tokens.size()) return nullptr;

        string token = tokens[index++];
        if(token == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserialize(tokens, index);
        root->right = deserialize(tokens, index);

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
