class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        if (root == nullptr)
            return root;

        // Step 1: Calculate sum of every level
        vector<int> levelwisesum;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            int sum = 0;

            for (int i = 0; i < n; i++) {

                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left != nullptr)
                    q.push(temp->left);

                if (temp->right != nullptr)
                    q.push(temp->right);
            }

            levelwisesum.push_back(sum);
        }

       
        queue<TreeNode*> q1;
        q1.push(root);

        root->val = 0;

        int idx = 0;

        while (!q1.empty()) {

            int n = q1.size();

            for (int i = 0; i < n; i++) {

                TreeNode* temp = q1.front();
                q1.pop();

    
                int siblingSum = 0;

                if (temp->left != nullptr)
                    siblingSum += temp->left->val;

                if (temp->right != nullptr)
                    siblingSum += temp->right->val;


                if (temp->left != nullptr) {

                    int newValue =
                        levelwisesum[idx + 1] - siblingSum;

                    temp->left->val = newValue;
                    q1.push(temp->left);
                }

                
                if (temp->right != nullptr) {

                    int newValue =
                        levelwisesum[idx + 1] - siblingSum;

                    temp->right->val = newValue;
                    q1.push(temp->right);
                }
            }

            idx++;
        }

        return root;
    }
};