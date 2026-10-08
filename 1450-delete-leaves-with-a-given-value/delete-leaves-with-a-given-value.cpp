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

    TreeNode* find(TreeNode* root,int tar){


        if(!root) return NULL;

        root->left = find(root->left,tar);
        root->right = find(root->right,tar);

        if(root -> val == tar && !root->left && !root->right) return NULL;

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int tar) {
        return find(root,tar);
    }
};