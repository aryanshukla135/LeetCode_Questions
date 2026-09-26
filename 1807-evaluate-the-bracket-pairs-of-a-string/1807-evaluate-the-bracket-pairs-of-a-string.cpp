class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n = s.length();
        int m = k.size();
        unordered_map<string,string> mp ;
        for(int i =0 ;i<m ; i++){
            mp[k[i][0]] = k[i][1];
        }
        int j =0 ;
        string ans = "";
        for(int i =0 ; i<n ; i++){
            if(s[i] == '('){
                int k = i+1 ;
                string str = "";
                while( k<n && s[k] != ')'){
                     str += s[k];
                     k++;
                }
                i = k;
                if(mp.count(str)){
                    ans += mp[str]; 
                }else{
                    ans += '?';
                }
            }else{
                ans += s[i];
            }
        }
        return ans ;
    }
};