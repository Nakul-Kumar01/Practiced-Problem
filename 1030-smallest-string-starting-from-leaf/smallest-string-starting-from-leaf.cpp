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

    void find(TreeNode* root,string curr,string& ans){
        if(!root) return;

        if(!root->left && !root->right){
           curr = char(root->val + 'a') + curr;

           if(ans == "") ans = curr;
           else if(ans > curr) ans = curr;
        }

        char c = root->val + 'a';

        find(root->left,c+curr,ans);
        find(root->right,c+curr,ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        find(root,"",ans);
        return ans;
    }
};