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

    int find(TreeNode* root,int t,map<pair<TreeNode*,int>,int>&m){
        if(!root) return 0;

        if(m.count({root,t})) return m[{root,t}];

        if(t) return m[{root,t}] = find(root->left,0,m) + find(root->right,0,m);

        return m[{root,t}] = max(find(root->left,0,m) + find(root->right,0,m),root->val +  find(root->left,1,m) + find(root->right,1,m));
    }

    int rob(TreeNode* root) {
        
        map<pair<TreeNode*,int>,int>m;
        return find(root,0,m);
    }
};