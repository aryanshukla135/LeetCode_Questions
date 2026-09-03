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
    TreeNode*solve(string& traversal,int& index , int level){
        if(index >= traversal.size()){
            return nullptr;
        }
        int j = index ;
        while(j < traversal.size() && traversal[j] == '-'){
            j++;
        }
        int dash = j - index ;
        if(dash != level){
            return nullptr;
        }
        index += dash ;
        int num =0 ;
        while(index < traversal.length() && isdigit(traversal[index])){
             num = num * 10 + ( traversal[index] - '0');
             index++;
        }
        TreeNode*root =new TreeNode(num);
        root -> left = solve(traversal,index,level+1);
        root -> right = solve(traversal,index,level+1);

        return root ;
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index =0 ;
        int level =0 ;
        return solve(traversal,index,level);
    }
};