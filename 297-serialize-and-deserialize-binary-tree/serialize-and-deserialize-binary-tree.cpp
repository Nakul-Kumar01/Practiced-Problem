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
    void find(TreeNode* root,string &s){
        if(!root){
            s += "1001,";
            return ;
        }


        s += to_string(root->val) + ",";


        find(root->left,s);
        find(root->right,s);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";


        find(root,s);
        return s;
    }

    TreeNode* build(int &i,string &s){

        string x = "";
        while(s[i] != ','){
            x += s[i];
            i++;
        }

        int num = stoi(x);
        i++;
        if(num == 1001) return NULL;
        TreeNode* node = new TreeNode(num);
        node -> left = build(i,s);
        node -> right = build(i,s);
        return node;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int i =0;
        return build(i,s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));