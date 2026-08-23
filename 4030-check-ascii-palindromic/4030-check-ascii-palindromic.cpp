class Solution {
private:
 string solve(int n) {
   // string ans ="";
    int tobinary = 0;
    int place = 1;

    while (n != 0) {
        int bit = n & 1;

        tobinary = tobinary + bit * place;

        place *= 10;
        n = n >> 1;
    }
    string str = to_string(tobinary);
    int len = str.length();
    int idx = 8 - len;
    string ans(8,'0');
    int j = 0;

    for(int i = idx ; i<8 ; i++){
          ans[i] = str[j++];
    }
    
    return ans ;
}
public:
    bool isPalindromic(string s) {
       int n = s.length();
       string str = "";
       for(int i =0 ; i<n ; i++){
          int num = (int)(s[i]);
          str += solve(num);
       }
       int i =0 ;
       int j = str.length()-1;
       while(i<j){
         if(str[i] != str[j]) return false;
         i++;
         j--;
       }
       return true;
    }
};
//1101 10+10
// 110