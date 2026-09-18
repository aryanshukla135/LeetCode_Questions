class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.length();

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1)
                first[idx] = i;
            last[idx] = i;
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] != i)
                continue;

            int j = last[s[i] - 'a'];
            bool valid = true;
            for (int k = i; k <= j; k++) {
                int idx = s[k] - 'a';
                if (first[idx] < i) {
                    valid = false;
                    break;
                }
                j = max(j, last[idx]);
            }

            if (valid) {
                intervals.push_back({i, j});
            }
        }
        vector<string> ans;
        int prevLast = -1;
        for (auto [l, r] : intervals) {

            if (l > prevLast) {
                ans.push_back(s.substr(l, r - l + 1));
                prevLast = r;
            }
            else {
                if (r < prevLast) {
                    ans.back() = s.substr(l, r - l + 1);
                    prevLast = r;
                }
            }
        }

        return ans;
    }
};