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
    void solve(TreeNode*root,unordered_set<int> & st){
        if(root == nullptr){
            return ;
        }
        st.insert(root->val);
        solve(root->left,st);
        solve(root->right,st);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int,vector<int> , greater<int>> pq ;
        unordered_set<int> st ;
        solve(root,st);

        if(st.size()<=1){
            return -1;
        }
        for(auto it : st){
            pq.push(it);
        }
        pq.pop();

        return pq.top();
       
    }
};