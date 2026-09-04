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
    int getHeight(TreeNode*root){
        if(root == nullptr){
            return 0 ;
        }
        int l = getHeight(root->left);
        int r = getHeight(root->right);

        return max(l,r)+1;
    }
void solve(TreeNode* root, vector<vector<string>>& ans,int r, int c, int h) {

        if (root == nullptr) {
            return;
        }

        ans[r][c] = to_string(root->val);

        if (r == h - 1) {
            return;
        }

        int offset = 1 << (h - r - 2);

        solve(root->left, ans, r + 1, c - offset, h);
        solve(root->right, ans, r + 1, c + offset, h);
}
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int n = h;
        int m = (1 << h) - 1;
        vector<vector<string>> ans(n,vector<string>(m,""));
        solve(root,ans,0,(m-1)/2,h);
        return ans ;
    }
};