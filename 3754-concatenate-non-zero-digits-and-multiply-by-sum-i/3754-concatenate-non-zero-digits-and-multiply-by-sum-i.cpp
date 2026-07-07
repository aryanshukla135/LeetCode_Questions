class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = "";
        long long x = n ;
        long long sum =0 ;
        while(x>0){
            long long dig= x%10 ;
            char num = dig + '0';
            if(dig != 0){
                str+=num;
                sum +=(num-'0');
            }
            x = x/10 ;

        }
        reverse(str.begin(),str.end());
        long long  nums = 0;
        if(str.size() != 0){
          nums = stoi(str);
        }
        
        return (nums*sum);
      return 0;
    }
};