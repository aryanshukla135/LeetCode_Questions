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
    bool f(TreeNode*r1,TreeNode*r2){
        if(r1 == nullptr && r2 == nullptr){
            return true ;
        }
        if(r1 == nullptr || r2 == nullptr){
            return false;
        }
        if(r1 ->val != r2->val){
            return false;
        }
        bool l = f(r1->left,r2->left);
        bool r = f(r1->right,r2->right);

        return l && r ;
    }
    bool solve(TreeNode*r1,TreeNode*r2){
         if(r1 == nullptr){
            return false;
         }
         bool ans = false;
         if(r1 -> val == r2 -> val){
            ans =  f(r1,r2);
            if(ans){
                return true;
            }
         }
         bool l = solve(r1->left,r2);
         bool r = solve(r1->right,r2);

         return l || r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         return solve(root,subRoot);
    }
};