class Solution {
public:
    string removeOuterParentheses(string s) {
         int n = s.length();
         string ans = "";
           
         int cnt = 0;
         int j =0 ;
         for(int i =0 ; i<n ; i++){
            if(s[i] == '('){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                if(i - j > 1){
                    string str = s.substr(j+1,i-j-1);
                    ans += str;
                }
                j = i + 1 ;
            }
         }
         return ans ;
    }
};