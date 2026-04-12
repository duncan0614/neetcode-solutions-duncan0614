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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> ret;
        fillNumber(root, level, &ret);
        return ret;
    }

private:
    void fillNumber(TreeNode* node, int level, vector<vector<int>>* numList) {
        if (node == nullptr) {
            return;
        }

        if (numList -> size() == level) {
            numList -> push_back(vector<int>());
        }

        (*numList)[level].push_back(node -> val);
        level += 1;

        fillNumber(node -> left, level, numList);
        fillNumber(node -> right, level, numList);
        return;
    }
};
