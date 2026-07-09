class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int idx = 0;

        string ans = s;

        while (idx < n && s[idx] == 'a') {
            idx++;
        }

        if (idx == n) {
            ans[n - 1] = 'z';
            return ans;
        }

        while (idx < n && ans[idx] != 'a') {
            ans[idx]--;
            idx++;
        }

        return ans;
    }
};