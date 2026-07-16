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
    void solve(TreeNode* root , vector<int>& nums,int& idx){
        if(root == nullptr){
            return ;
        }
        solve(root->left,nums,idx);
        if(root->val != nums[idx]){
            root->val = nums[idx];
            idx++;
        }else{
            idx++;
        }
        solve(root->right,nums,idx);
       


    }
    void inorder(TreeNode*root,vector<int> & nums){
        if(root == nullptr){
            return ;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        int idx=0;
        
        sort(nums.begin(),nums.end());

        solve(root,nums,idx);
    }

};