class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int ans = -1;
        unordered_map<char,int> mp ;
        for(int i =0 ; i<n ; i++){
            if(mp.count(s[i])){
                int len = i- mp[s[i]]-1;
                ans = max(ans,len);
            }else{
                mp[s[i]] = i;
            }
        }
        return ans ;
    }
};