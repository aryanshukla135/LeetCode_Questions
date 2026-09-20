class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans =0 ;
        for(int i =0 ; i<n ; i++){
            int val = (i+1) * ('z'-s[i]+1);
            ans += val;
        }
        return ans ;
    }
};