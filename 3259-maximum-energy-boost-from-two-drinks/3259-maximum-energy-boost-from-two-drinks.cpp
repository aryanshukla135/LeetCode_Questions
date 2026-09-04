class Solution {
private:
    long long f(vector<int>& A, vector<int>& B,
                int i, int j,
                vector<vector<long long>>& dp) {

        if(i < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(j == 0) {
            // End with A at i
            long long fromA =
                A[i] + f(A, B, i - 1, 0, dp);

            // Switch B -> A:
            // i-1 is wasted, A[i] is taken
            long long switchToA =
                A[i] + f(A, B, i - 2, 1, dp);

            return dp[i][j] = max(fromA, switchToA);
        }
        else {
            // End with B at i
            long long fromB =
                B[i] + f(A, B, i - 1, 1, dp);

            // Switch A -> B:
            // i-1 is wasted, B[i] is taken
            long long switchToB =
                B[i] + f(A, B, i - 2, 0, dp);

            return dp[i][j] = max(fromB, switchToB);
        }
    }

public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {

        int n = A.size();

        vector<vector<long long>> dp(
            n, vector<long long>(2, -1)
        );

        return max(
            f(A, B, n - 1, 0, dp),
            f(A, B, n - 1, 1, dp)
        );
    }
};