class Solution {
private:  
    string digitSum(string & s){
        int sum =0 ;
        int n = s.length();
        for(int i = 0 ; i<n ; i++){
            sum += (s[i] - '0');
        }

        string str = to_string(sum);
        return str;
    }
public:
    string digitSum(string s, int k) {

        while(s.length() > k){
            string s1 = "";
            for(int i =0 ; i<s.length(); i++){
                    int cnt = 0 ;
                    string str ="";
                    while(i<s.length() && cnt !=k){
                        str += s[i];
                        i++;
                        cnt++;
                    }
                     i--;
                     s1 += digitSum(str);
             }
             s = s1 ;
        }
        return s ;
    }
};