class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1 ;
        int i =0 ;
        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
              sign = -1;
            }
            i++;
        }

        long long num = 0;
        while(i<n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');

            if(sign == 1){
                if(num > INT_MAX){
                    return INT_MAX;
                }
            }
            if(sign == -1){
                if(num > -(long long)INT_MIN){
                    return INT_MIN;
                }
            }
            i++;
        }
        return num*sign;
    }
};