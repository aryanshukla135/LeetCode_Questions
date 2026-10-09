
class Solution {
private:
    bool ispossible(vector<int>& freq) {
        int prev = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (prev == -1) {
                    prev = freq[i];
                } else if (prev != freq[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    int solve(string &s, int i, vector<int> &dp) {
        if (i == s.length()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = INT_MAX;
        vector<int> freq(26, 0);

        for (int j = i; j < s.length(); j++) {
            freq[s[j] - 'a']++;

            if (ispossible(freq)) {
                int count = 1 + solve(s, j + 1, dp);
                mini = min(mini, count);
            }
        }

        return dp[i] = mini;
    }

public:
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};
