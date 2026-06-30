class Solution {
private :
    bool allone(unordered_map<char,int> &mp){
        if(mp['a']>0 && mp['b']>0 && mp['c'] >0){
            return true ;
        }
        return false;
    }

public:
    int numberOfSubstrings(string s) {
         int n = s.length();

         int cnt = 0;
         unordered_map<char,int> mp;

         int i =0; 
         int j = 0;

         while(i<n && j<n){
            char ch = s[i];
            mp[ch]++;
    
            while(allone(mp)){
                cnt = cnt+(n-i);
                mp[s[j]]--;
                j++;
            }
            i++;
         }
         return cnt ;

    }
};