
class Solution {
private:
    int solve(vector<vector<int>>& nums, int i,int minPrice, int target,
              vector<vector<int>>& dp) {

        if (i < 0) {
            return target/minPrice;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int nottake = solve(nums, i - 1,minPrice, target, dp);

        int take = 0;
        int val = nums[i][1];

        if(target >= val){
            take = 1 + nums[i][2] + solve(nums,i-1,minPrice,target - val , dp);
        }

        return dp[i][target] = max(take, nottake);
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int val = items[i][0];
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % val == 0) {
                    cnt++;
                }
            }

            items[i].push_back(cnt);
        }

        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));

        return solve(items, n - 1, minPrice,budget, dp);
    }
};
