class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int cnt =0 ;
        int i =0 ;
        while(i<n-1){
            if(s[i] != s[i+1]){
               ++cnt;
            }
            i+=2;
        }
        return cnt;
    }
};