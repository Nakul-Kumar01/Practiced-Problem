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

    TreeNode* find(TreeNode* root,int val,int d){

        if(d == 2){
            TreeNode* nodel = new TreeNode(val);
            nodel ->left = root->left;
            TreeNode* noder = new TreeNode(val);
            noder -> right = root->right;
            root ->left = nodel;
            root->right = noder;
            return root;
        }


        if(root->left) root->left = find(root->left,val,d-1);
        if(root->right) root->right = find(root->right,val,d-1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        return find(root,val,depth);
    }
};