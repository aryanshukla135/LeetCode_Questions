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
   
    // {sum,{nodecnt,cnt}
   pair<int,pair<int,int>> totalsum(TreeNode*root){
                if(root==nullptr){
                    pair<int,pair<int,int>> p = {0,{0,0}};
                    return p ;
                }

              pair<int,pair<int,int>> l =totalsum(root->left);
              pair<int,pair<int,int>> r =totalsum(root->right);

              pair<int,pair<int,int>> ans ;
              ans.first = l.first + r.first + root->val ;
              ans.second.first = l.second.first + r.second.first + 1 ;
              int avg = (ans.first) / (ans.second.first);
              ans.second.second = l.second.second + r.second.second;
              
              if(avg == root->val){
                 ans.second.second = ans.second.second + 1;
              }


             return ans ;
    }
    // void allRoot(TreeNode*root ,int &count){
    //     if(root == nullptr){
    //         return ;
    //     }
        
    //    pair<int,int> p = totalsum(root ,0,0);
    //    int val = p.first ;
    //    int total = p.second;
    //    int avg = val/total;
    //    if(avg==root->val){
    //      count++;
    //    }
    //    allRoot(root->left,count);
    //    allRoot(root->right ,count);

    // }
public:
    int averageOfSubtree(TreeNode* root) {
        pair<int,pair<int,int>> ans = totalsum(root);
        return ans.second.second;
    }
};