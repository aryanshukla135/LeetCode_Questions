class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.length();
         int m = t.length();
         int cnt = 0 ;
         int strtIndex = -1 ;
         int maxLength = INT_MAX ;
         unordered_map<char,int> mp ;
         int j =0 ;
         for(int i =0 ; i<m ; i++){
            mp[t[i]]++;
         }

         for(int i =0 ; i<n ; i++){
            if(mp[s[i]] > 0) cnt = cnt +1 ;
            mp[s[i]]--;

            while(cnt == m){
                if(i-j+1 < maxLength){
                    maxLength = i-j+1;
                    strtIndex = j ;
                }
                mp[s[j]]++;
                if(mp[s[j]] > 0){
                    cnt--;
                }
                j++;
            }
         }
         return strtIndex == -1 ? "" : s.substr(strtIndex,maxLength);
    }
};