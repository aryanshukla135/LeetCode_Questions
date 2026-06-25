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
    // tc-> O(N^2)
    // int height(TreeNode* root){
    //     if(root == nullptr){
    //         return 0;
    //     }

    //     int l = height(root->left);
    //     int r = height(root->right);

    //     return max(l,r) + 1 ;
    // }
    //{diameter,height}
    //tc->O(n)
    pair<int,int> fastsolve(TreeNode*root){

        if(root == nullptr){
            return {0,0};
        }

        pair<int,int> l = fastsolve(root->left);
        pair<int,int> r = fastsolve(root->right);

        pair<int,int> ans ;
        ans.first =max(l.first,max(r.first,l.second+r.second));
        ans.second = max(l.second,r.second)+1;

        return ans ;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == nullptr){
        //     return 0 ;
        // }

        // int op1 = diameterOfBinaryTree(root->left);
        // int op2 = diameterOfBinaryTree(root->right);

        // int op3 = height(root->left) + height(root->right);

        return fastsolve(root).first;
    }
};