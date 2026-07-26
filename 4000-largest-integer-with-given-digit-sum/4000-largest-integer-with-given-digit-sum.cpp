class Solution {
private :
    int digitsum(int n ){
        int sum =0 ;
        while(n>0){
            int rem = n % 10 ;
            sum += rem ;
            n /= 10;
        }
        return sum ;
    }
public:
    int largestInteger(int n, int s) {
        if(s > 9*n){
            return -1; 
        }
        int ans = INT_MIN;
        if(n >=1 && n<2){
            for(int i =0 ; i<10 ; i++){
                int digits = digitsum(i);
                if(s == digits){
                    ans = max(i,ans);
                }
            }
        }else if(n>=2 && n<3){
            for(int i = 10 ; i<100 ; i++){
                int digits = digitsum(i);
                if(s == digits){
                    ans = max(i,ans);
                }
            }
        }else if(n>=3 && n<4){
            for(int i = 100 ; i<1000 ; i++){
                int digits = digitsum(i);
                if(s == digits){
                    ans = max(i,ans);
                }
            }
        }else if(n>=4 && n<5){
            for(int i = 1000 ; i<10000 ; i++){
                int digits = digitsum(i);
                if(s == digits){
                    ans = max(i,ans);
                }
            }
        }else{
            for(int i = 0 ;i<100000; i++){
                int digits = digitsum(i);
                if(s == digits){
                    ans = max(i,ans);
                }
            }
        }
        if(ans == INT_MIN){
            return s ;
        }
        return ans ;
    }
};
