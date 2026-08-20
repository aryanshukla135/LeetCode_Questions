class Solution {
private:
    string reverse(string & s){
        int n =s.length();
        int i =0 ;
        int j =n-1;

        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }



public:
    string addBinary(string a, string b) {
       
        int n = a.length();
        int m = b.length();

        string s1 = reverse(a);
        string s2 = reverse(b);
        string ans = "";

        int carry = 0;
        int i =0 ;
        int j =0 ;
        while(i<n || j<m || carry != 0){
            int val1 = 0;
            if(i<n){
                val1 = s1[i]-'0';
                i++;
            }
            int val2 = 0;
            if(j<m){
                val2 = s2[j]-'0';
                j++;
            }
            int val = val1 + val2 + carry ;
            if(val == 2){
                carry = 1;
                val = 0 ;
            }else if(val == 3){
                carry = 1;
                val=1;
            }
            else{
                carry = 0;
            }
            ans += (val +'0');
        }
        
        return reverse(ans); 
    }
};
// 1101
// 0101
// 10101