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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*>s;
        while(root){
            s.push(root);
            root = root -> left;
        }

        vector<int>ans;


        while(!s.empty()){
            ans.push_back(s.top()->val);
            TreeNode* curr = s.top()->right;
            s.pop();
            while(curr){
                s.push(curr);
                curr = curr ->left;
            }
        }
        return ans;
    }
};