class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int cnt =0;
        int ans = 0;
        for(int i =0 ; i<n ; i++){
            if(s[i] == '('){
                cnt++;
            }
            if(s[i] == ')'){
                ans = max(ans,cnt);
                cnt--;
            }
            
        }
        return ans ;
    }
};