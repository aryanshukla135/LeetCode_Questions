class Solution {
private:
    bool allvowel(vector<int>& last) {
        return last[0] != -1 && last[1] != -1 && last[2] != -1 && last[3] != -1 &&
        last[4] != -1;
    }

public:
    long long countOfSubstrings(string word, int k) {

        int n = word.size();

        long long ans = 0;
        int cons = 0;
        int j = 0;

        vector<int> last(5, -1);
        vector<int> consonants;

        for (int i = 0; i < n; i++) {

            char ch = word[i];

            if (ch == 'a')
                last[0] = i;
            else if (ch == 'e')
                last[1] = i;
            else if (ch == 'i')
                last[2] = i;
            else if (ch == 'o')
                last[3] = i;
            else if (ch == 'u')
                last[4] = i;
            else{
                cons++;
                consonants.push_back(i);
            }
                

            while (cons > k) {
                char c = word[j];
                if (c != 'a' && c != 'e' &&
                    c != 'i' && c != 'o' &&
                    c != 'u') {
                    cons--;
                }
                j++;
            }
            if (cons == k && allvowel(last)) {

                int minLast = min({last[0],last[1],last[2],last[3],last[4]});
                 if (k == 0) {
                    if (minLast >= j)
                        ans += minLast - j + 1;
                }
                else {
                    int kthCons = consonants[consonants.size() - k];
                    int limit = min(minLast, kthCons);
                    if (limit >= j)
                        ans += limit - j + 1;
                }
            }
        }

        return ans;
    }
};