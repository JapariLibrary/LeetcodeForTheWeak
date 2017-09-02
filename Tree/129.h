/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root, sum, 0);
        return sum;
    }
private:
    void traverse(TreeNode* node, int& sum, int val) {
        if (!node) return;
        val = val * 10 + node->val;
        if (!node->left && !node->right) {
            sum += val;
        } else {
            traverse(node->left, sum, val);
            traverse(node->right, sum, val);
        }
    }
};