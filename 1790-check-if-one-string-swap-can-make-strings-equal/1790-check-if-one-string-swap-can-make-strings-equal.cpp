class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        unordered_map<char,int> mp ;

        for(int i =0 ;i<n ; i++){
            mp[s1[i]]++;
        }

        int cnt =0 ;
        for(int i =0 ; i<n ; i++){
            if(mp[s2[i]]==0){
                return false;
            }
            if(s1[i] != s2[i] ){
                cnt++;
            }
            if(cnt>2){
                return false ;
            }
            mp[s2[i]]--;
        }
        return cnt<=2;
    }
};