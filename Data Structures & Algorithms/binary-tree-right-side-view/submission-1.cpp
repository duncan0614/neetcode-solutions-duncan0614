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
    vector<int> ret;
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        ret = fillNumber(root, level);
        return ret;
    }

private:
    vector<int> fillNumber(TreeNode* root, int level) {
        if (!root) {
            return ret;
        }

        if (ret.size() == level) {
            ret.push_back(root -> val);
        }

        fillNumber(root -> right, level + 1);
        fillNumber(root -> left, level + 1);

        return ret;
    }
};
