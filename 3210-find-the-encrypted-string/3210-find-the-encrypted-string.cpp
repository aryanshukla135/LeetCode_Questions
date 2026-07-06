class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        k = k % n;
        string ans =s.substr(k,n) +s.substr(0,k) ;
        return ans ;
    }
};