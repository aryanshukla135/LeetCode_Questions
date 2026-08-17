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
private:
    int depth(TreeNode*root ,int value ){
        if(root == nullptr){
            return -1 ;
        }
        if(root->val == value ){
            return 0 ;
        }
        int l = depth(root->left,value);
        int r = depth(root->right,value);

        if(l == -1 && r == -1){
            return -1;
        }else if(l == -1){
            return r+1;
        }else{
            return l+1;
        }
    }
    int parent(TreeNode*root,int value){
        if(root == nullptr){
            return -1;
        }
        if(root ->left != NULL ){
           if(root->left->val == value){
             return root->val;
           }
        }
         if(root ->right != NULL ){
           if(root->right->val == value){
             return root->val;
           }
        }
        int l = parent(root->left,value);
        int r = parent(root->right,value);

        if(l == -1 && r == -1){
            return -1 ;
        }
        else if(l == -1){
            return r ;
        }else{
            return l ;
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int f = depth(root,x);
        int s = depth(root,y);

        int parf = parent(root,x);
        int pars = parent(root,y);


        if(f == s && parf != pars){
            return true;
        }
        return false;
    }
};