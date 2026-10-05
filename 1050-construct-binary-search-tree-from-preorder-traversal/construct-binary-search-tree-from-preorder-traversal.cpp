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
int n;

    TreeNode* find(int &i,int mini,int maxi,vector<int>& arr){
        if(i==n) return NULL;

        
        if(arr[i] >=mini && arr[i] <=maxi){
            TreeNode* node = new TreeNode(arr[i++]);

            node ->left = find(i,mini,node->val,arr);
            node ->right = find(i,node->val,maxi,arr);
            return node;
        }
        return NULL;
    }

    TreeNode* bstFromPreorder(vector<int>& arr) {
         n = arr.size();
         int  i=0;
        return find(i,1,1000,arr);
    }
};