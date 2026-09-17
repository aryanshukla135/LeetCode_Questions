class Solution {
private:
    bool isPallindrome(string & s){
        int n = s.length();
        int i =0 ;
        int j = n-1 ;
        while(i<j){
            if(s[i] != s[j] ){
                return false;
            }
              i++;
              j--;
    
        }
        return true ;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i =0 ;
        int j = n-1 ;
        
        while(i<j){
            if(s[i] != s[j]){
                break;
            }
            i++;
            j--;
        }
        if(i >= j){
            return true;
        }
        cout<<i<<" "<<j;
        string s2 = s.substr(i + 1, j - i);
      
        bool first = isPallindrome(s2);
        string s1 = s.substr(i, j - i);

        bool second = isPallindrome(s1);
        return first || second;

    }
};