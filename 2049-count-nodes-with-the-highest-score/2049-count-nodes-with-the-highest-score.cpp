long long solve(TreeNode* root, int total, long long& maxi, int& count) {
    if (root == nullptr) {
        return 0;
    }

    long long left = solve(root->left, total, maxi, count);
    long long right = solve(root->right, total, maxi, count);

    long long rem = total - (left + right + 1);

    long long score = 1;

    if (left > 0) score *= left;
    if (right > 0) score *= right;
    if (rem > 0) score *= rem;

    if (score > maxi) {
        maxi = score;
        count = 1;
    } else if (score == maxi) {
        count++;
    }

    return left + right + 1;
}

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();

        vector<TreeNode*> nodes(n);

        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(i);
        }

        TreeNode* root = nullptr;

        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = nodes[i];
            } else {
                TreeNode* p = nodes[parents[i]];

                if (p->left == nullptr) {
                    p->left = nodes[i];
                } else {
                    p->right = nodes[i];
                }
            }
        }

        long long maxi = 0;
        int count = 0;

        solve(root, n, maxi, count);

        return count;
    }
};