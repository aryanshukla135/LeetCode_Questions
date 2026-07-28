class Solution {
public:
    string smallestPalindrome(string s) {
         int n = s.length();
         string ans = "";
         string left = "";
         string mid = "";

         vector<int> freq(26,0);
         for(int i =0 ; i<n ; i++){
            int idx = s[i]-'a';
            freq[idx]++;
         }
         
         for(int i =0 ;i<26; i++){
             int val = freq[i] /2 ;

             while(val--){
                 char ch = i+'a';
                 left += ch ;
             }
             if(freq[i] % 2 != 0){
                 char ch = i + 'a';
                 mid += ch ;
             }
         }
         ans += left + mid ;
         reverse(left.begin(),left.end());
         ans += left;

         return ans ;
    }
};