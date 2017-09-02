/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* node, ostringstream& out) {
        if (node) {
            out << to_string(node->val) << " ";
            serialize(node->left, out);
            serialize(node->right, out);
        } else {
            out << "# ";
        }
    }
    
    TreeNode* deserialize(istringstream& in) {
        string str;
        in >> str;
        if (str == "#") {
            return nullptr;
        } else {
            TreeNode *node = new TreeNode(stoi(str));
            node->left = deserialize(in);
            node->right = deserialize(in);
            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));